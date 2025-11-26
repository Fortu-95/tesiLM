#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <vector>
#include <string>

class AverageNode : public rclcpp::Node
{
public:
  AverageNode()
  : Node("average_node")
  {
    N = this->declare_parameter<int>("num_nodes");

    inputs.assign(N, 0.0);
    states.assign(N, 0.0);

    for (int i = 0; i < N; ++i) {
      std::string topic_in = "/node_" + std::to_string(i) + "/input";
      auto sub_in = this->create_subscription<std_msgs::msg::Float64>(
        topic_in, 10,
        [this, i](const std_msgs::msg::Float64::SharedPtr msg) {
          inputs[i] = msg->data;
        });
      subs_input.push_back(sub_in);
    }

    for (int i = 0; i < N; ++i) {
      std::string topic_st = "/node_" + std::to_string(i) + "/state";
      auto sub_st = this->create_subscription<std_msgs::msg::Float64>(
        topic_st, 10,
        [this, i](const std_msgs::msg::Float64::SharedPtr msg) {
          states[i] = msg->data;
        });
      subs_state.push_back(sub_st);
    }

    avg_input_pub = this->create_publisher<std_msgs::msg::Float64>("/average_input", 10);
    avg_state_pub = this->create_publisher<std_msgs::msg::Float64>("/average_state", 10);

    timer = this->create_wall_timer(
      std::chrono::milliseconds(200),
      std::bind(&AverageNode::publish_averages, this)
    );

  }

private:
  void publish_averages()
  {
    double sum_in = 0.0, sum_st = 0.0;
    for (int i = 0; i < N; ++i) {
      sum_in += inputs[i];
      sum_st += states[i];
    }

    std_msgs::msg::Float64 msg_in, msg_st;
    msg_in.data = sum_in / static_cast<double>(N);
    msg_st.data = sum_st / static_cast<double>(N);

    avg_input_pub->publish(msg_in);
    avg_state_pub->publish(msg_st);
  }

  int N;
  std::vector<double> inputs, states;
  std::vector<rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr> subs_input, subs_state;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr avg_input_pub, avg_state_pub;
  rclcpp::TimerBase::SharedPtr timer;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<AverageNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}