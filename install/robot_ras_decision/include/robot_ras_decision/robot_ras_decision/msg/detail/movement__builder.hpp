// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_ras_decision:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__BUILDER_HPP_
#define ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_ras_decision/msg/detail/movement__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_ras_decision
{

namespace msg
{

namespace builder
{

class Init_Movement_angulo
{
public:
  explicit Init_Movement_angulo(::robot_ras_decision::msg::Movement & msg)
  : msg_(msg)
  {}
  ::robot_ras_decision::msg::Movement angulo(::robot_ras_decision::msg::Movement::_angulo_type arg)
  {
    msg_.angulo = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_ras_decision::msg::Movement msg_;
};

class Init_Movement_distancia
{
public:
  explicit Init_Movement_distancia(::robot_ras_decision::msg::Movement & msg)
  : msg_(msg)
  {}
  Init_Movement_angulo distancia(::robot_ras_decision::msg::Movement::_distancia_type arg)
  {
    msg_.distancia = std::move(arg);
    return Init_Movement_angulo(msg_);
  }

private:
  ::robot_ras_decision::msg::Movement msg_;
};

class Init_Movement_direcao
{
public:
  Init_Movement_direcao()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Movement_distancia direcao(::robot_ras_decision::msg::Movement::_direcao_type arg)
  {
    msg_.direcao = std::move(arg);
    return Init_Movement_distancia(msg_);
  }

private:
  ::robot_ras_decision::msg::Movement msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_ras_decision::msg::Movement>()
{
  return robot_ras_decision::msg::builder::Init_Movement_direcao();
}

}  // namespace robot_ras_decision

#endif  // ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__BUILDER_HPP_
