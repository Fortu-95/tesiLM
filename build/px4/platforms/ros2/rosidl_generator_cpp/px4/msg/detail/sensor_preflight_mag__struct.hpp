// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from px4:msg/SensorPreflightMag.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__SENSOR_PREFLIGHT_MAG__STRUCT_HPP_
#define PX4__MSG__DETAIL__SENSOR_PREFLIGHT_MAG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__px4__msg__SensorPreflightMag __attribute__((deprecated))
#else
# define DEPRECATED__px4__msg__SensorPreflightMag __declspec(deprecated)
#endif

namespace px4
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SensorPreflightMag_
{
  using Type = SensorPreflightMag_<ContainerAllocator>;

  explicit SensorPreflightMag_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0ull;
      this->mag_inconsistency_angle = 0.0f;
    }
  }

  explicit SensorPreflightMag_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0ull;
      this->mag_inconsistency_angle = 0.0f;
    }
  }

  // field types and members
  using _timestamp_type =
    uint64_t;
  _timestamp_type timestamp;
  using _mag_inconsistency_angle_type =
    float;
  _mag_inconsistency_angle_type mag_inconsistency_angle;

  // setters for named parameter idiom
  Type & set__timestamp(
    const uint64_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__mag_inconsistency_angle(
    const float & _arg)
  {
    this->mag_inconsistency_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    px4::msg::SensorPreflightMag_<ContainerAllocator> *;
  using ConstRawPtr =
    const px4::msg::SensorPreflightMag_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<px4::msg::SensorPreflightMag_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<px4::msg::SensorPreflightMag_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      px4::msg::SensorPreflightMag_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<px4::msg::SensorPreflightMag_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      px4::msg::SensorPreflightMag_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<px4::msg::SensorPreflightMag_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<px4::msg::SensorPreflightMag_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<px4::msg::SensorPreflightMag_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__px4__msg__SensorPreflightMag
    std::shared_ptr<px4::msg::SensorPreflightMag_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__px4__msg__SensorPreflightMag
    std::shared_ptr<px4::msg::SensorPreflightMag_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SensorPreflightMag_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->mag_inconsistency_angle != other.mag_inconsistency_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const SensorPreflightMag_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SensorPreflightMag_

// alias to use template instance with default allocator
using SensorPreflightMag =
  px4::msg::SensorPreflightMag_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace px4

#endif  // PX4__MSG__DETAIL__SENSOR_PREFLIGHT_MAG__STRUCT_HPP_
