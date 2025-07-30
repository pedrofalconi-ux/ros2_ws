// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_ras_decision:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__STRUCT_H_
#define ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'direcao'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Movement in the package robot_ras_decision.
typedef struct robot_ras_decision__msg__Movement
{
  rosidl_runtime_c__String direcao;
  float distancia;
  float angulo;
} robot_ras_decision__msg__Movement;

// Struct for a sequence of robot_ras_decision__msg__Movement.
typedef struct robot_ras_decision__msg__Movement__Sequence
{
  robot_ras_decision__msg__Movement * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_ras_decision__msg__Movement__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__STRUCT_H_
