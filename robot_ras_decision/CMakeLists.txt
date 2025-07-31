cmake_minimum_required(VERSION 3.8)
project(robot_ras_decision)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate messages and services
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Movement.msg"
  "srv/SetVelocity.srv"
  DEPENDENCIES std_msgs
)

# Manager executable
add_executable(manager src/moviment/manager.cpp)
target_include_directories(manager PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(manager PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(manager
  "rclcpp"
  "sensor_msgs"
)

# Movement Control executable
add_executable(moviment_control src/moviment/moviment_control.cpp)
target_include_directories(moviment_control PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(moviment_control PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(moviment_control
  "rclcpp"
  "std_msgs"
)

# Link custom messages/services to executables
rosidl_target_interfaces(manager ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(moviment_control ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Install executables
install(TARGETS 
  manager
  moviment_control
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
