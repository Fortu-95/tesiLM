cmake_minimum_required(VERSION 3.5)
project(cameras)

find_package(ament_cmake REQUIRED)
find_package(gazebo_ros REQUIRED)

install(
  DIRECTORY models
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()

