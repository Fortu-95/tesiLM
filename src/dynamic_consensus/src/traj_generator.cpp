#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/float64_multi_array.hpp"
#include <vector>
#include <memory>
#include <cmath>

class TrajectoryPublisher : public rclcpp::Node
{
public:
    TrajectoryPublisher(int N) : Node("trajectory_publisher"), N(N)
    {
        double pub_rate = 50.0;
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(static_cast<int>(1000.0 / pub_rate)),
            std::bind(&TrajectoryPublisher::publish_signals, this));
        for (int i = 0; i < N; ++i)
        {
            std::string topic = "/node_" + std::to_string(i) + "/input";
            pubs_.push_back(this->create_publisher<example_interfaces::msg::Float64MultiArray>(topic, 10));
        }
    }

private:
    void publish_signals()
    {
        time_ += 0.02;
        for (int i = 0; i < N; ++i)
        {
            std::vector<double> data(6);

            if (i == 0)
            {
                std::fill(data.begin(), data.end(), 0.0);
            }
            else
            {
                double t = time_ + (i * 0.2);
                data[0] = 1.0 * std::cos(t);
                data[1] = 1.0 * std::sin(t);
                data[2] = 0.5 * std::sin(0.5 * t);
                data[3] = -1.0 * std::sin(t);
                data[4] = 1.0 * std::cos(t);
                data[5] = 0.25 * std::cos(0.5 * t);
            }

            example_interfaces::msg::Float64MultiArray msg;
            msg.data = data;
            pubs_[i]->publish(msg);
        }
    }

    int N;
    rclcpp::TimerBase::SharedPtr timer_;
    std::vector<rclcpp::Publisher<example_interfaces::msg::Float64MultiArray>::SharedPtr> pubs_;
    double time_ = 0.0;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    int N = 5;
    auto node = std::make_shared<TrajectoryPublisher>(N);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
