#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/float64_multi_array.hpp"
#include <eigen3/Eigen/Dense>
#include <vector>
#include <memory>

class NodoConsenso : public rclcpp::Node
{
public:
    NodoConsenso() : Node("nodo")
    {
        this->declare_parameter("id", 0);
        id_ = this->get_parameter("id").as_int();

        this->declare_parameter("N", 8);
        N = this->get_parameter("N").as_int();

        std::vector<int> neighbors_vec(2);

        if (id_ == 0)
        {
            neighbors_vec = {N - 1, 1};
        }
        else if (id_ == N - 1)
        {
            neighbors_vec = {N - 2, 0};
        }
        else
        {
            neighbors_vec = {id_ - 1, id_ + 1};
        }

        idl = neighbors_vec[0];
        idr = neighbors_vec[1];

        auto V_topicl = "/node_" + std::to_string(neighbors_vec[0]) + "/V";
        auto v_topicl = "/node_" + std::to_string(neighbors_vec[0]) + "/v";
        auto V_topicr = "/node_" + std::to_string(neighbors_vec[1]) + "/V";
        auto v_topicr = "/node_" + std::to_string(neighbors_vec[1]) + "/v";

        auto V_subl = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
            V_topicl,
            100,
            [this, idl = this->idl](const example_interfaces::msg::Float64MultiArray::SharedPtr msg)
            {
                neighbor_Vl = Eigen::Map<Eigen::MatrixXd>(msg->data.data(), 6, 6);
            });

        auto v_subl = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
            v_topicl,
            100,
            [this, idl = this->idl](const example_interfaces::msg::Float64MultiArray::SharedPtr msg)
            {
                neighbor_vl = Eigen::Map<Eigen::VectorXd>(msg->data.data(), 6);
            });

        auto V_subr = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
            V_topicr,
            100,
            [this, idr = this->idr](const example_interfaces::msg::Float64MultiArray::SharedPtr msg)
            {
                neighbor_Vr = Eigen::Map<Eigen::MatrixXd>(msg->data.data(), 6, 6);
            });

        auto v_subr = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
            v_topicr,
            100,
            [this, idr = this->idr](const example_interfaces::msg::Float64MultiArray::SharedPtr msg)
            {
                neighbor_vr = Eigen::Map<Eigen::VectorXd>(msg->data.data(), 6);
            });

        V_subs.push_back(V_subl);
        v_subs.push_back(v_subl);
        V_subs.push_back(V_subr);
        v_subs.push_back(v_subr);

        std::string topic_V = "/node_" + std::to_string(id_) + "/V";
        std::string topic_v = "/node_" + std::to_string(id_) + "/v";

        pub_V_ = this->create_publisher<example_interfaces::msg::Float64MultiArray>(topic_V, 10);
        pub_v_ = this->create_publisher<example_interfaces::msg::Float64MultiArray>(topic_v, 10);

        input_sub = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
            "/node_" + std::to_string(id_) + "/input",
            10,
            [this](const example_interfaces::msg::Float64MultiArray::SharedPtr msg)
            {
                z = Eigen::Map<Eigen::VectorXd>(msg->data.data(), 6);

                if (!x_priori_initialized_)
                {
                    x_priori = z;
                    x_priori_initialized_ = true;
                }

                icf12();
                icf3();
                icf4();
                icf5();
            });
        x_post = Eigen::VectorXd::Zero(6);

        std::string topic_x = "/node_" + std::to_string(id_) + "/x_post";
        pub_x_post_ = this->create_publisher<example_interfaces::msg::Float64MultiArray>(topic_x, 10);

        V_ = Eigen::MatrixXd::Zero(6, 6);
        v_ = Eigen::VectorXd::Zero(6);
        neighbor_Vl = Eigen::MatrixXd::Zero(6, 6);
        neighbor_Vr = Eigen::MatrixXd::Zero(6, 6);
        neighbor_vl = Eigen::VectorXd::Zero(6);
        neighbor_vr = Eigen::VectorXd::Zero(6);
        Eigen::MatrixXd P_pre_iniz = Eigen::MatrixXd::Zero(6, 6);
        P_pre_iniz.diagonal() << 100.0, 100.0, 100.0, 10.0, 10.0, 10.0;

        J_priori = P_pre_iniz.inverse();

        H_ = Eigen::MatrixXd(3, 6);
        H_ << 1, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 0, 0,
            0, 0, 1, 0, 0, 0;
        R_ = Eigen::MatrixXd::Identity(3, 3) * 100;
        Q_ = Eigen::MatrixXd(6, 6);
        Q_ << 10, 0, 0, 0, 0, 0,
            0, 10, 0, 0, 0, 0,
            0, 0, 10, 0, 0, 0,
            0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 1;
        Phi_ = Eigen::MatrixXd(6, 6);
        Phi_ << 1, 0, 0, 1, 0, 0,
            0, 1, 0, 0, 1, 0,
            0, 0, 1, 0, 0, 1,
            0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 1;
        x_priori = Eigen::VectorXd::Zero(6);
        x_post = Eigen::VectorXd::Zero(6);
        J_post = Eigen::MatrixXd::Zero(6, 6);
        V_dyn_ = Eigen::MatrixXd::Zero(6, 6);
        QV_ = Eigen::MatrixXd::Zero(6, 6);
        PV_ = Eigen::MatrixXd::Zero(6, 6);

        v_dyn_ = Eigen::VectorXd::Zero(6);
        Qv_ = Eigen::VectorXd::Zero(6);
        Pv_ = Eigen::VectorXd::Zero(6);
    }

private:
    int id_;
    int N;
    int idl, idr;
    bool x_priori_initialized_ = false;
    double kP_ = 0.1;
    double kI_ = 0.01;
    Eigen::VectorXd x_priori;
    Eigen::MatrixXd J_priori;
    Eigen::VectorXd x_post;
    Eigen::MatrixXd J_post;
    Eigen::MatrixXd V_;
    Eigen::MatrixXd neighbor_Vl;
    Eigen::MatrixXd neighbor_Vr;
    Eigen::MatrixXd neighbor_vl;
    Eigen::MatrixXd neighbor_vr;
    Eigen::VectorXd v_;
    Eigen::MatrixXd H_;
    Eigen::MatrixXd Phi_;
    Eigen::MatrixXd R_;
    Eigen::MatrixXd Q_;
    Eigen::MatrixXd V_dyn_;
    Eigen::MatrixXd V_prev_;
    Eigen::MatrixXd QV_;
    Eigen::MatrixXd PV_;
    Eigen::VectorXd v_dyn_;
    Eigen::VectorXd v_prev_;
    Eigen::VectorXd Qv_;
    Eigen::VectorXd Pv_;
    Eigen::VectorXd z;

    rclcpp::Publisher<example_interfaces::msg::Float64MultiArray>::SharedPtr pub_stima_;
    rclcpp::Subscription<example_interfaces::msg::Float64MultiArray>::SharedPtr sub_misura_;
    rclcpp::Subscription<example_interfaces::msg::Float64MultiArray>::SharedPtr sub_left_;
    rclcpp::Subscription<example_interfaces::msg::Float64MultiArray>::SharedPtr sub_right_;

    std::vector<rclcpp::Subscription<example_interfaces::msg::Float64MultiArray>::SharedPtr> V_subs;
    std::vector<rclcpp::Subscription<example_interfaces::msg::Float64MultiArray>::SharedPtr> v_subs;
    rclcpp::Publisher<example_interfaces::msg::Float64MultiArray>::SharedPtr pub_V_;
    rclcpp::Publisher<example_interfaces::msg::Float64MultiArray>::SharedPtr pub_v_;
    rclcpp::Publisher<example_interfaces::msg::Float64MultiArray>::SharedPtr pub_x_post_;

    rclcpp::Subscription<example_interfaces::msg::Float64MultiArray>::SharedPtr input_sub;
    rclcpp::TimerBase::SharedPtr timer_;

    double epsilon = 0.325;

    void icf12()
    {
        Eigen::Vector3d z_short = z.head(3);

        V_ = (1.0 / N) * J_priori + H_.transpose() * R_.inverse() * H_;
        v_ = (1.0 / N) * J_priori * x_priori + H_.transpose() * R_.inverse() * z_short;

        publish_V();
        publish_v();
    }

    void icf3()
    {
        V_prev_ = V_;
        v_prev_ = v_;

        Eigen::MatrixXd somm_V = (V_dyn_ - neighbor_Vl) + (V_dyn_ - neighbor_Vr);
        Eigen::VectorXd somm_v = (v_dyn_ - neighbor_vl) + (v_dyn_ - neighbor_vr);

        QV_ += kP_ * somm_V + (V_ - V_prev_);
        Qv_ += kP_ * somm_v + (v_ - v_prev_);

        PV_ += kI_ * somm_V;
        Pv_ += kI_ * somm_v;

        V_dyn_ = V_ - QV_ - PV_;
        v_dyn_ = v_ - Qv_ - Pv_;

        V_ = V_dyn_;
        v_ = v_dyn_;

        V_prev_ = V_;
        v_prev_ = v_;

        publish_V();
        publish_v();
    }

    void icf4()
    {
        x_post = V_.inverse() * v_;
        J_post = N * V_;
        publish_x_post();
    }
    void icf5()
    {
        Eigen::MatrixXd J_post_inv = J_post.inverse();
        J_priori = (Phi_ * J_post_inv * Phi_.transpose() + Q_).inverse();

        x_priori = Phi_ * x_post;
    }
    void publish_V()
    {
        example_interfaces::msg::Float64MultiArray msg;
        msg.data.reserve(36);

        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                msg.data.push_back(V_(i, j));
            }
        }
        pub_V_->publish(msg);
    }

    void publish_v()
    {
        example_interfaces::msg::Float64MultiArray msg;
        msg.data.reserve(6);

        for (int i = 0; i < 6; ++i)
        {
            msg.data.push_back(v_(i));
        }
        pub_v_->publish(msg);
    }
    void publish_x_post()
    {
        example_interfaces::msg::Float64MultiArray msg;
        msg.data.reserve(6);
        for (int i = 0; i < 6; ++i)
        {
            msg.data.push_back(x_post(i));
        }
        pub_x_post_->publish(msg);
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto nodo = std::make_shared<NodoConsenso>();
    rclcpp::spin(nodo);
    rclcpp::shutdown();
    return 0;
}