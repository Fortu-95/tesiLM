#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <map>
#include <mutex>

class ConsensusNode : public rclcpp::Node
{
public:
    ConsensusNode(int id)
        : Node("node_" + std::to_string(id)), id(id)
    {
        id = this->declare_parameter("node_id", id);
        int N = this->declare_parameter("num_nodes", 5);

        neighbors.clear();
        if (id == 0) {
            neighbors = {N - 1, 1};
        } else if (id == N - 1) {
            neighbors = {N - 2, 0};
        } else {
            neighbors = {id - 1, id + 1};
        }

        H = 1.0;
        Q = 10.0;
        B = 0.01;
        epsilon = 0.65 / 2;
        J_iniz = 100.0;
        Phi = 1.0;
        Kt = 5;

        x = 0.0;
        z = 0.0;
        alpha = 2.0;
        rho = 0.6;
        lambda = 1.0;
        kp = 0.1;
        ki = 0.2;
        dt = 0.1;

        J = J_iniz;

        state_pub = this->create_publisher<std_msgs::msg::Float64>(
            "/node_" + std::to_string(id) + "/state", 10);

        V_pub = this->create_publisher<std_msgs::msg::Float64>(
            "/node_" + std::to_string(id) + "/V", 10);
        v_pub = this->create_publisher<std_msgs::msg::Float64>(
            "/node_" + std::to_string(id) + "/v", 10);

        neighbor_states.assign(N, 0.0);

        for (int i : neighbors) {
            auto topic_name = "/node_" + std::to_string(i) + "/state";
            auto sub = this->create_subscription<std_msgs::msg::Float64>(
                topic_name,
                10,
                [this, i](const std_msgs::msg::Float64::SharedPtr msg) {
                    neighbor_states[i] = msg->data;
                });
            neighbor_subs.push_back(sub);
        }

        for (int i : neighbors) {
            auto V_topic = "/node_" + std::to_string(i) + "/V";
            auto v_topic = "/node_" + std::to_string(i) + "/v";
            
            auto V_sub = this->create_subscription<std_msgs::msg::Float64>(
                V_topic,
                100,
                [this, i](const std_msgs::msg::Float64::SharedPtr msg) {
                    {
                        std::lock_guard<std::mutex> lock(comm_mutex);
                        neighbor_V[i] = msg->data;
                    }
                });
            
            auto v_sub = this->create_subscription<std_msgs::msg::Float64>(
                v_topic,
                100,
                [this, i](const std_msgs::msg::Float64::SharedPtr msg) {
                    {
                        std::lock_guard<std::mutex> lock(comm_mutex);
                        neighbor_v[i] = msg->data;
                    }
                });
            
            V_subs.push_back(V_sub);
            v_subs.push_back(v_sub);
        }

        input_sub = this->create_subscription<std_msgs::msg::Float64>(
            "/node_" + std::to_string(id) + "/input",
            10,
            [this](const std_msgs::msg::Float64::SharedPtr msg) {
                u = msg->data;
            });

        timer = this->create_wall_timer(
            std::chrono::duration<double>(dt),
            std::bind(&ConsensusNode::update_state, this));
    }

private:
    void icf_algorithm()
    {
        int N = (int)neighbor_states.size();
        
        double V = (1.0 / N) * J + H * H * B;
        double v = (1.0 / N) * J * x + H * B * u;
        
        
        std::vector<double> V_corr(Kt + 1);
        std::vector<double> v_corr(Kt + 1);
        V_corr[0] = V;
        v_corr[0] = v;
        
        for (int k = 1; k <= Kt; ++k) {
            publish_V_v(V_corr[k - 1], v_corr[k - 1]);
            
            rclcpp::sleep_for(std::chrono::milliseconds(10));
            
            double V_neighbor1, v_neighbor1, V_neighbor2, v_neighbor2;
            {
                std::lock_guard<std::mutex> lock(comm_mutex);
                V_neighbor1 = neighbor_V[neighbors[0]];
                v_neighbor1 = neighbor_v[neighbors[0]];
                V_neighbor2 = neighbor_V[neighbors[1]];
                v_neighbor2 = neighbor_v[neighbors[1]];
            }
            
            double V_new = V_corr[k - 1] + epsilon * 
                          ((V_neighbor1 - V_corr[k - 1]) + (V_neighbor2 - V_corr[k - 1]));
            double v_new = v_corr[k - 1] + epsilon * 
                          ((v_neighbor1 - v_corr[k - 1]) + (v_neighbor2 - v_corr[k - 1]));
            
            V_corr[k] = V_new;
            v_corr[k] = v_new;
            
        }
        
        double V_final = V_corr[Kt];
        double v_final = v_corr[Kt];
        

        double x_posteriori = v_final / V_final;
        
        double J_posteriori = N * V_final;
        
        double denom_J = (Phi * Phi / J_posteriori) + Q;

        double J_priori = 1.0 / denom_J;
        
        double x_priori = Phi * x_posteriori;
        
        x = x_posteriori;
        J = J_priori;
        

    }
    
    void publish_V_v(double V, double v)
    {
        std_msgs::msg::Float64 V_msg;
        V_msg.data = V;
        V_pub->publish(V_msg);
        
        std_msgs::msg::Float64 v_msg;
        v_msg.data = v;
        v_pub->publish(v_msg);
    }
    
    void update_state()
    {
        icf_algorithm();
        
        // int round = 10;
        int round = 1;              
        double round_dt = dt / round;

        for (int k = 0; k < round; ++k) {
            double lap_sum = 0.0;
            for (int j : neighbors) {
                lap_sum += (x - neighbor_states[j]);
            }

            double dx = -kp * lap_sum + alpha * (u - x) + z;
            z += ki * (-lap_sum) * round_dt;

            x += dx * round_dt;
        }

        std_msgs::msg::Float64 msg;
        msg.data = x;
        state_pub->publish(msg);
    }

    double H;
    double Q;
    double B;
    double epsilon;
    double J_iniz;
    double Phi;
    int Kt;
    double J;
    
    int id;
    std::vector<int> neighbors;
    std::vector<double> neighbor_states;
    double x;
    double z;
    double u = 0.0;
    double alpha, rho, lambda, kp, ki;
    double dt;
    
    std::map<int, double> neighbor_V;
    std::map<int, double> neighbor_v;
    std::mutex comm_mutex;

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr state_pub;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr V_pub;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr v_pub;
    
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr input_sub;
    std::vector<rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr> neighbor_subs;
    std::vector<rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr> V_subs;
    std::vector<rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr> v_subs;
    
    rclcpp::TimerBase::SharedPtr timer;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ConsensusNode>(0);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}