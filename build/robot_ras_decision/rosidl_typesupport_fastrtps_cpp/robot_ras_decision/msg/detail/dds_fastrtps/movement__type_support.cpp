// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robot_ras_decision:msg/Movement.idl
// generated code does not contain a copyright notice
#include "robot_ras_decision/msg/detail/movement__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robot_ras_decision/msg/detail/movement__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace robot_ras_decision
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_ras_decision
cdr_serialize(
  const robot_ras_decision::msg::Movement & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: direcao
  cdr << ros_message.direcao;
  // Member: distancia
  cdr << ros_message.distancia;
  // Member: angulo
  cdr << ros_message.angulo;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_ras_decision
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robot_ras_decision::msg::Movement & ros_message)
{
  // Member: direcao
  cdr >> ros_message.direcao;

  // Member: distancia
  cdr >> ros_message.distancia;

  // Member: angulo
  cdr >> ros_message.angulo;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_ras_decision
get_serialized_size(
  const robot_ras_decision::msg::Movement & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: direcao
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.direcao.size() + 1);
  // Member: distancia
  {
    size_t item_size = sizeof(ros_message.distancia);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angulo
  {
    size_t item_size = sizeof(ros_message.angulo);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_ras_decision
max_serialized_size_Movement(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: direcao
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: distancia
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: angulo
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robot_ras_decision::msg::Movement;
    is_plain =
      (
      offsetof(DataType, angulo) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Movement__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robot_ras_decision::msg::Movement *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Movement__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robot_ras_decision::msg::Movement *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Movement__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robot_ras_decision::msg::Movement *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Movement__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Movement(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Movement__callbacks = {
  "robot_ras_decision::msg",
  "Movement",
  _Movement__cdr_serialize,
  _Movement__cdr_deserialize,
  _Movement__get_serialized_size,
  _Movement__max_serialized_size
};

static rosidl_message_type_support_t _Movement__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Movement__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace robot_ras_decision

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robot_ras_decision
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_ras_decision::msg::Movement>()
{
  return &robot_ras_decision::msg::typesupport_fastrtps_cpp::_Movement__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_ras_decision, msg, Movement)() {
  return &robot_ras_decision::msg::typesupport_fastrtps_cpp::_Movement__handle;
}

#ifdef __cplusplus
}
#endif
