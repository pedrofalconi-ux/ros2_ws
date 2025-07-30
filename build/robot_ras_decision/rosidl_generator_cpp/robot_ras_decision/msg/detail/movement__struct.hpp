// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_ras_decision:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__STRUCT_HPP_
#define ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_ras_decision__msg__Movement __attribute__((deprecated))
#else
# define DEPRECATED__robot_ras_decision__msg__Movement __declspec(deprecated)
#endif

namespace robot_ras_decision
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Movement_
{
  using Type = Movement_<ContainerAllocator>;

  explicit Movement_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->direcao = "";
      this->distancia = 0.0f;
      this->angulo = 0.0f;
    }
  }

  explicit Movement_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : direcao(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->direcao = "";
      this->distancia = 0.0f;
      this->angulo = 0.0f;
    }
  }

  // field types and members
  using _direcao_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _direcao_type direcao;
  using _distancia_type =
    float;
  _distancia_type distancia;
  using _angulo_type =
    float;
  _angulo_type angulo;

  // setters for named parameter idiom
  Type & set__direcao(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->direcao = _arg;
    return *this;
  }
  Type & set__distancia(
    const float & _arg)
  {
    this->distancia = _arg;
    return *this;
  }
  Type & set__angulo(
    const float & _arg)
  {
    this->angulo = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_ras_decision::msg::Movement_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_ras_decision::msg::Movement_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_ras_decision::msg::Movement_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_ras_decision::msg::Movement_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_ras_decision::msg::Movement_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_ras_decision::msg::Movement_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_ras_decision::msg::Movement_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_ras_decision::msg::Movement_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_ras_decision::msg::Movement_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_ras_decision::msg::Movement_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_ras_decision__msg__Movement
    std::shared_ptr<robot_ras_decision::msg::Movement_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_ras_decision__msg__Movement
    std::shared_ptr<robot_ras_decision::msg::Movement_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Movement_ & other) const
  {
    if (this->direcao != other.direcao) {
      return false;
    }
    if (this->distancia != other.distancia) {
      return false;
    }
    if (this->angulo != other.angulo) {
      return false;
    }
    return true;
  }
  bool operator!=(const Movement_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Movement_

// alias to use template instance with default allocator
using Movement =
  robot_ras_decision::msg::Movement_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_ras_decision

#endif  // ROBOT_RAS_DECISION__MSG__DETAIL__MOVEMENT__STRUCT_HPP_
