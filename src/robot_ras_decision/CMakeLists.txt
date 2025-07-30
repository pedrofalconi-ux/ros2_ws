cmake_minimum_required(VERSION 3.8)
project(robot_ras_decision)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rosidl_default_runtime REQUIRED) 

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Movement.msg"     
  "srv/SetVelocity.srv"
)

ament_export_dependencies(rosidl_default_runtime)

add_executable(MovementControl src/moviment_control.cpp)
ament_target_dependencies(MovementControl rclcpp std_msgs sensor_msgs rosidl_default_runtime)
rosidl_target_interfaces(MovementControl ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(Manager src/manager.cpp)
ament_target_dependencies(Manager rclcpp std_msgs sensor_msgs rosidl_default_runtime)
rosidl_target_interfaces(Manager ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(TARGETS
  MovementControl
  Manager
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
