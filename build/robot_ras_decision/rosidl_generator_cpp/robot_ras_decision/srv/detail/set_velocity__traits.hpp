// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_ras_decision:srv/SetVelocity.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_RAS_DECISION__SRV__DETAIL__SET_VELOCITY__TRAITS_HPP_
#define ROBOT_RAS_DECISION__SRV__DETAIL__SET_VELOCITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_ras_decision/srv/detail/set_velocity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_ras_decision
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetVelocity_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: velocity
  {
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetVelocity_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetVelocity_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_ras_decision

namespace rosidl_generator_traits
{

[[deprecated("use robot_ras_decision::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_ras_decision::srv::SetVelocity_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_ras_decision::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_ras_decision::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_ras_decision::srv::SetVelocity_Request & msg)
{
  return robot_ras_decision::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_ras_decision::srv::SetVelocity_Request>()
{
  return "robot_ras_decision::srv::SetVelocity_Request";
}

template<>
inline const char * name<robot_ras_decision::srv::SetVelocity_Request>()
{
  return "robot_ras_decision/srv/SetVelocity_Request";
}

template<>
struct has_fixed_size<robot_ras_decision::srv::SetVelocity_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_ras_decision::srv::SetVelocity_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_ras_decision::srv::SetVelocity_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_ras_decision
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetVelocity_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetVelocity_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetVelocity_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_ras_decision

namespace rosidl_generator_traits
{

[[deprecated("use robot_ras_decision::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_ras_decision::srv::SetVelocity_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_ras_decision::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_ras_decision::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_ras_decision::srv::SetVelocity_Response & msg)
{
  return robot_ras_decision::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_ras_decision::srv::SetVelocity_Response>()
{
  return "robot_ras_decision::srv::SetVelocity_Response";
}

template<>
inline const char * name<robot_ras_decision::srv::SetVelocity_Response>()
{
  return "robot_ras_decision/srv/SetVelocity_Response";
}

template<>
struct has_fixed_size<robot_ras_decision::srv::SetVelocity_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_ras_decision::srv::SetVelocity_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_ras_decision::srv::SetVelocity_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_ras_decision::srv::SetVelocity>()
{
  return "robot_ras_decision::srv::SetVelocity";
}

template<>
inline const char * name<robot_ras_decision::srv::SetVelocity>()
{
  return "robot_ras_decision/srv/SetVelocity";
}

template<>
struct has_fixed_size<robot_ras_decision::srv::SetVelocity>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_ras_decision::srv::SetVelocity_Request>::value &&
    has_fixed_size<robot_ras_decision::srv::SetVelocity_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_ras_decision::srv::SetVelocity>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_ras_decision::srv::SetVelocity_Request>::value &&
    has_bounded_size<robot_ras_decision::srv::SetVelocity_Response>::value
  >
{
};

template<>
struct is_service<robot_ras_decision::srv::SetVelocity>
  : std::true_type
{
};

template<>
struct is_service_request<robot_ras_decision::srv::SetVelocity_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_ras_decision::srv::SetVelocity_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_RAS_DECISION__SRV__DETAIL__SET_VELOCITY__TRAITS_HPP_
