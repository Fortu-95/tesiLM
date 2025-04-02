cmake_minimum_required(VERSION 3.5)
project(tuo_pacchetto)


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(example_interfaces REQUIRED)


find_package(rosidl_default_generators REQUIRED)

add_executable(nodo src/nodo.cpp)
ament_target_dependencies(nodo rclcpp std_msgs)
ament_target_dependencies(nodo rclcpp example_interfaces)

install(TARGETS nodo
    DESTINATION lib/${PROJECT_NAME})

ament_package()

