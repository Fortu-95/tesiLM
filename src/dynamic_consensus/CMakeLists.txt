cmake_minimum_required(VERSION 3.8)
project(dynamic_consensus)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(consensus_node src/consensus_node.cpp)
ament_target_dependencies(consensus_node rclcpp std_msgs)

add_executable(signal_generator_node src/signal_generator_node.cpp)
ament_target_dependencies(signal_generator_node rclcpp std_msgs)

add_executable(average_calc_node src/average_calc_node.cpp)
ament_target_dependencies(average_calc_node rclcpp std_msgs)

install(TARGETS
  consensus_node
  signal_generator_node
  average_calc_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

ament_package()

