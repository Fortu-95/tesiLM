#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <cmath>
#include <sstream>

class SignalGeneratorNode : public rclcpp::Node {
public:
  SignalGeneratorNode() : Node("signal_generator_node")
  {
    node_id_ = this->declare_parameter<int>("node_id", 0);
    dt_ = 0.05;

    std::ostringstream ns;
    ns << "/node_" << node_id_ << "/input";
    pub_ = this->create_publisher<std_msgs::msg::Float64>(ns.str(), 10);

    
    timer_ = this->create_wall_timer(
      std::chrono::duration<double>(dt_),
      std::bind(&SignalGeneratorNode::step, this));

    RCLCPP_INFO(this->get_logger(), "Signal generator node_%d started", node_id_);
  }

private:
  double signal_formula(double t, int L)
  {
    // if (L == 5)
    //   return 0.0;

    double base = std::pow(t / 20.0, 2);
    double sine = 0.5 * std::sin((0.35 + 0.05 * L) * t + (5.0 - L) * M_PI / 5.0);
    double offset = 4.0 - 2.0 * (L - 1);
    return base + sine + offset;
  }

  void step()
  {
    t_ += dt_*0.01;
    double val = signal_formula(t_, node_id_ + 1);

    auto msg = std_msgs::msg::Float64();
    msg.data = val;
    pub_->publish(msg);
  }

  int node_id_;
  double dt_, t_ = 0.0;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SignalGeneratorNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
