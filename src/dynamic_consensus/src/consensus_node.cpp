#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include <vector>
#include <string>
#include <cmath>
#include <random>

class ConsensusNode : public rclcpp::Node
{
public:
    ConsensusNode(int id)
    : Node("node_" + std::to_string(id)), id(id)
    {
        id = this->declare_parameter<int>("node_id", id);
        int N = this->declare_parameter<int>("num_nodes", 5);
        neighbors.clear();
        if (id == 0) {
            neighbors = {N - 1, 1};
        } else if (id == N - 1) {
            neighbors = {N - 2, 0};
        } else {
            neighbors = {id - 1, id + 1};
        }

        x = 0.0;
        z = 0.0;

        alpha = 1.0;
        rho   = 0.6;
        lambda = 1.0;
        kp = 0.1;
        ki = 0.2;
        

        dt = 0.05;

        state_pub = this->create_publisher<std_msgs::msg::Float64>(
            "/node_" + std::to_string(id) + "/state", 10);

        neighbor_states.assign(N, 0.0);
        for (int i : neighbors) {
            auto topic_name = "/node_" + std::to_string(i) + "/state";
            auto sub = this->create_subscription<std_msgs::msg::Float64>(
                topic_name,
                10,
                [this, i](const std_msgs::msg::Float64::SharedPtr msg) {
                    neighbor_states[i] = msg->data;
                }
            );
            neighbor_subs.push_back(sub);
        }

        input_sub = this->create_subscription<std_msgs::msg::Float64>(
            "/node_" + std::to_string(id) + "/input",
            10,
            [this](const std_msgs::msg::Float64::SharedPtr msg) {
                u = msg->data;
            }
        );

        timer = this->create_wall_timer(
            std::chrono::duration<double>(dt),
            std::bind(&ConsensusNode::update_state, this)
        );
    }

private:
    // void update_state()
    // {
    //     double lap_sum = 0.0;
    //     for (int j : neighbors) {
    //         lap_sum += (x - neighbor_states[j]);
    //     }

    //     double dx = -kp * lap_sum + alpha * (u - x) + z;
    //     z += ki * dt * (-lap_sum);

    //     x += dx * dt;

    //     std_msgs::msg::Float64 msg;
    //     msg.data = x;
    //     state_pub->publish(msg);
    // }

    void update_state()
{
    int round = 10;              
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


    int id;
    std::vector<int> neighbors;
    std::vector<double> neighbor_states;

    double x;
    double z;
    double u = 0.0;

    double alpha, rho, lambda, kp, ki;
    double dt;

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr state_pub;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr input_sub;
    std::vector<rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr> neighbor_subs;
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
