// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_ras_decision:srv/SetVelocity.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_RAS_DECISION__SRV__DETAIL__SET_VELOCITY__BUILDER_HPP_
#define ROBOT_RAS_DECISION__SRV__DETAIL__SET_VELOCITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_ras_decision/srv/detail/set_velocity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_ras_decision
{

namespace srv
{

namespace builder
{

class Init_SetVelocity_Request_velocity
{
public:
  Init_SetVelocity_Request_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_ras_decision::srv::SetVelocity_Request velocity(::robot_ras_decision::srv::SetVelocity_Request::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_ras_decision::srv::SetVelocity_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_ras_decision::srv::SetVelocity_Request>()
{
  return robot_ras_decision::srv::builder::Init_SetVelocity_Request_velocity();
}

}  // namespace robot_ras_decision


namespace robot_ras_decision
{

namespace srv
{

namespace builder
{

class Init_SetVelocity_Response_message
{
public:
  explicit Init_SetVelocity_Response_message(::robot_ras_decision::srv::SetVelocity_Response & msg)
  : msg_(msg)
  {}
  ::robot_ras_decision::srv::SetVelocity_Response message(::robot_ras_decision::srv::SetVelocity_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_ras_decision::srv::SetVelocity_Response msg_;
};

class Init_SetVelocity_Response_success
{
public:
  Init_SetVelocity_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetVelocity_Response_message success(::robot_ras_decision::srv::SetVelocity_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetVelocity_Response_message(msg_);
  }

private:
  ::robot_ras_decision::srv::SetVelocity_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_ras_decision::srv::SetVelocity_Response>()
{
  return robot_ras_decision::srv::builder::Init_SetVelocity_Response_success();
}

}  // namespace robot_ras_decision

#endif  // ROBOT_RAS_DECISION__SRV__DETAIL__SET_VELOCITY__BUILDER_HPP_
