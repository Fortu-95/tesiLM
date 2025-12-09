cmake_minimum_required(VERSION 3.8)
project(dynamic_consensus)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(example_interfaces REQUIRED)


add_executable(consensus_node src/consensus_node.cpp)
ament_target_dependencies(consensus_node rclcpp std_msgs)
target_link_libraries(consensus_node Eigen3::Eigen)

add_executable(signal_generator_node src/signal_generator_node.cpp)
ament_target_dependencies(signal_generator_node rclcpp std_msgs)

add_executable(average_calc_node src/average_calc_node.cpp)
ament_target_dependencies(average_calc_node rclcpp std_msgs)


add_executable(nodo src/nodo.cpp)
ament_target_dependencies(nodo rclcpp example_interfaces Eigen3)

add_executable(traj_generator src/traj_generator.cpp)
ament_target_dependencies(traj_generator rclcpp example_interfaces)



install(TARGETS
  nodo
  consensus_node
  signal_generator_node
  average_calc_node
  traj_generator
  DESTINATION lib/${PROJECT_NAME}
)


install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
ament_package()
