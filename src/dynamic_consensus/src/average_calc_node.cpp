#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <vector>
#include <string>

class AggregatorNode : public rclcpp::Node
{
public:
  AggregatorNode(int N)
  : Node("aggregator_node"), N_(N)
  {
    inputs_.assign(N_, 0.0);
    states_.assign(N_, 0.0);

    for (int i = 0; i < N_; ++i) {
      std::string topic_in = "/node_" + std::to_string(i) + "/input";
      auto sub_in = this->create_subscription<std_msgs::msg::Float64>(
        topic_in, 10,
        [this, i](const std_msgs::msg::Float64::SharedPtr msg) {
          inputs_[i] = msg->data;
        });
      subs_input_.push_back(sub_in);
    }

    for (int i = 0; i < N_; ++i) {
      std::string topic_st = "/node_" + std::to_string(i) + "/state";
      auto sub_st = this->create_subscription<std_msgs::msg::Float64>(
        topic_st, 10,
        [this, i](const std_msgs::msg::Float64::SharedPtr msg) {
          states_[i] = msg->data;
        });
      subs_state_.push_back(sub_st);
    }

    avg_input_pub_ = this->create_publisher<std_msgs::msg::Float64>("/average_input", 10);
    avg_state_pub_ = this->create_publisher<std_msgs::msg::Float64>("/average_state", 10);

    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(200),
      std::bind(&AggregatorNode::publish_averages, this)
    );
  }

private:
  void publish_averages()
  {
    double sum_in = 0.0;
    double sum_st = 0.0;
    for (int i = 0; i < N_; ++i) {
      sum_in += inputs_[i];
      sum_st += states_[i];
    }
    double avg_in = sum_in / double(N_);
    double avg_st = sum_st / double(N_);

    std_msgs::msg::Float64 msg_in;
    msg_in.data = avg_in;
    avg_input_pub_->publish(msg_in);

    std_msgs::msg::Float64 msg_st;
    msg_st.data = avg_st;
    avg_state_pub_->publish(msg_st);
  }

  int N_;
  std::vector<double> inputs_;
  std::vector<double> states_;

  std::vector<rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr> subs_input_;
  std::vector<rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr> subs_state_;

  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr avg_input_pub_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr avg_state_pub_;

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  int N = 5;
  auto node = std::make_shared<AggregatorNode>(N);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
