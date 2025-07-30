// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_ras_decision:srv/SetVelocity.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_RAS_DECISION__SRV__DETAIL__SET_VELOCITY__STRUCT_H_
#define ROBOT_RAS_DECISION__SRV__DETAIL__SET_VELOCITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetVelocity in the package robot_ras_decision.
typedef struct robot_ras_decision__srv__SetVelocity_Request
{
  float velocity;
} robot_ras_decision__srv__SetVelocity_Request;

// Struct for a sequence of robot_ras_decision__srv__SetVelocity_Request.
typedef struct robot_ras_decision__srv__SetVelocity_Request__Sequence
{
  robot_ras_decision__srv__SetVelocity_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_ras_decision__srv__SetVelocity_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetVelocity in the package robot_ras_decision.
typedef struct robot_ras_decision__srv__SetVelocity_Response
{
  bool success;
  rosidl_runtime_c__String message;
} robot_ras_decision__srv__SetVelocity_Response;

// Struct for a sequence of robot_ras_decision__srv__SetVelocity_Response.
typedef struct robot_ras_decision__srv__SetVelocity_Response__Sequence
{
  robot_ras_decision__srv__SetVelocity_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_ras_decision__srv__SetVelocity_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_RAS_DECISION__SRV__DETAIL__SET_VELOCITY__STRUCT_H_
