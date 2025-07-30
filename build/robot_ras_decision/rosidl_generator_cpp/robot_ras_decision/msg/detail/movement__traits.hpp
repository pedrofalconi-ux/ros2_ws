// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_ras_decision:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__TRAITS_HPP_
#define ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_ras_decision/msg/detail/movement__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_ras_decision
{

namespace msg
{

inline void to_flow_style_yaml(
  const Movement & msg,
  std::ostream & out)
{
  out << "{";
  // member: direcao
  {
    out << "direcao: ";
    rosidl_generator_traits::value_to_yaml(msg.direcao, out);
    out << ", ";
  }

  // member: distancia
  {
    out << "distancia: ";
    rosidl_generator_traits::value_to_yaml(msg.distancia, out);
    out << ", ";
  }

  // member: angulo
  {
    out << "angulo: ";
    rosidl_generator_traits::value_to_yaml(msg.angulo, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Movement & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: direcao
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direcao: ";
    rosidl_generator_traits::value_to_yaml(msg.direcao, out);
    out << "\n";
  }

  // member: distancia
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distancia: ";
    rosidl_generator_traits::value_to_yaml(msg.distancia, out);
    out << "\n";
  }

  // member: angulo
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angulo: ";
    rosidl_generator_traits::value_to_yaml(msg.angulo, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Movement & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace robot_ras_decision

namespace rosidl_generator_traits
{

[[deprecated("use robot_ras_decision::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_ras_decision::msg::Movement & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_ras_decision::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_ras_decision::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_ras_decision::msg::Movement & msg)
{
  return robot_ras_decision::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_ras_decision::msg::Movement>()
{
  return "robot_ras_decision::msg::Movement";
}

template<>
inline const char * name<robot_ras_decision::msg::Movement>()
{
  return "robot_ras_decision/msg/Movement";
}

template<>
struct has_fixed_size<robot_ras_decision::msg::Movement>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_ras_decision::msg::Movement>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_ras_decision::msg::Movement>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__TRAITS_HPP_
