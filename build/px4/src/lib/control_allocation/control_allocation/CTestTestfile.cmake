# CMake generated Testfile for 
# Source directory: /home/fortunato/ros2_ws/src/PX4-Autopilot/src/lib/control_allocation/control_allocation
# Build directory: /home/fortunato/ros2_ws/build/px4/src/lib/control_allocation/control_allocation
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unit-ControlAllocationPseudoInverse "/home/fortunato/ros2_ws/build/px4/unit-ControlAllocationPseudoInverse")
set_tests_properties(unit-ControlAllocationPseudoInverse PROPERTIES  WORKING_DIRECTORY "/home/fortunato/ros2_ws/build/px4" _BACKTRACE_TRIPLES "/home/fortunato/ros2_ws/src/PX4-Autopilot/cmake/gtest/px4_add_gtest.cmake;71;add_test;/home/fortunato/ros2_ws/src/PX4-Autopilot/src/lib/control_allocation/control_allocation/CMakeLists.txt;46;px4_add_unit_gtest;/home/fortunato/ros2_ws/src/PX4-Autopilot/src/lib/control_allocation/control_allocation/CMakeLists.txt;0;")
add_test(functional-ControlAllocationSequentialDesaturation "/home/fortunato/ros2_ws/build/px4/functional-ControlAllocationSequentialDesaturation")
set_tests_properties(functional-ControlAllocationSequentialDesaturation PROPERTIES  _BACKTRACE_TRIPLES "/home/fortunato/ros2_ws/src/PX4-Autopilot/cmake/gtest/px4_add_gtest.cmake;125;add_test;/home/fortunato/ros2_ws/src/PX4-Autopilot/src/lib/control_allocation/control_allocation/CMakeLists.txt;47;px4_add_functional_gtest;/home/fortunato/ros2_ws/src/PX4-Autopilot/src/lib/control_allocation/control_allocation/CMakeLists.txt;0;")
