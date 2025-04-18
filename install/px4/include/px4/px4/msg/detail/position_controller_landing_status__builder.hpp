// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from px4:msg/PositionControllerLandingStatus.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__POSITION_CONTROLLER_LANDING_STATUS__BUILDER_HPP_
#define PX4__MSG__DETAIL__POSITION_CONTROLLER_LANDING_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "px4/msg/detail/position_controller_landing_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace px4
{

namespace msg
{

namespace builder
{

class Init_PositionControllerLandingStatus_abort_status
{
public:
  explicit Init_PositionControllerLandingStatus_abort_status(::px4::msg::PositionControllerLandingStatus & msg)
  : msg_(msg)
  {}
  ::px4::msg::PositionControllerLandingStatus abort_status(::px4::msg::PositionControllerLandingStatus::_abort_status_type arg)
  {
    msg_.abort_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4::msg::PositionControllerLandingStatus msg_;
};

class Init_PositionControllerLandingStatus_flaring
{
public:
  explicit Init_PositionControllerLandingStatus_flaring(::px4::msg::PositionControllerLandingStatus & msg)
  : msg_(msg)
  {}
  Init_PositionControllerLandingStatus_abort_status flaring(::px4::msg::PositionControllerLandingStatus::_flaring_type arg)
  {
    msg_.flaring = std::move(arg);
    return Init_PositionControllerLandingStatus_abort_status(msg_);
  }

private:
  ::px4::msg::PositionControllerLandingStatus msg_;
};

class Init_PositionControllerLandingStatus_lateral_touchdown_offset
{
public:
  explicit Init_PositionControllerLandingStatus_lateral_touchdown_offset(::px4::msg::PositionControllerLandingStatus & msg)
  : msg_(msg)
  {}
  Init_PositionControllerLandingStatus_flaring lateral_touchdown_offset(::px4::msg::PositionControllerLandingStatus::_lateral_touchdown_offset_type arg)
  {
    msg_.lateral_touchdown_offset = std::move(arg);
    return Init_PositionControllerLandingStatus_flaring(msg_);
  }

private:
  ::px4::msg::PositionControllerLandingStatus msg_;
};

class Init_PositionControllerLandingStatus_timestamp
{
public:
  Init_PositionControllerLandingStatus_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PositionControllerLandingStatus_lateral_touchdown_offset timestamp(::px4::msg::PositionControllerLandingStatus::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_PositionControllerLandingStatus_lateral_touchdown_offset(msg_);
  }

private:
  ::px4::msg::PositionControllerLandingStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4::msg::PositionControllerLandingStatus>()
{
  return px4::msg::builder::Init_PositionControllerLandingStatus_timestamp();
}

}  // namespace px4

#endif  // PX4__MSG__DETAIL__POSITION_CONTROLLER_LANDING_STATUS__BUILDER_HPP_
