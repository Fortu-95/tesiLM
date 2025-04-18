// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from px4:msg/PowerButtonState.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__POWER_BUTTON_STATE__BUILDER_HPP_
#define PX4__MSG__DETAIL__POWER_BUTTON_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "px4/msg/detail/power_button_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace px4
{

namespace msg
{

namespace builder
{

class Init_PowerButtonState_event
{
public:
  explicit Init_PowerButtonState_event(::px4::msg::PowerButtonState & msg)
  : msg_(msg)
  {}
  ::px4::msg::PowerButtonState event(::px4::msg::PowerButtonState::_event_type arg)
  {
    msg_.event = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4::msg::PowerButtonState msg_;
};

class Init_PowerButtonState_timestamp
{
public:
  Init_PowerButtonState_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PowerButtonState_event timestamp(::px4::msg::PowerButtonState::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_PowerButtonState_event(msg_);
  }

private:
  ::px4::msg::PowerButtonState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4::msg::PowerButtonState>()
{
  return px4::msg::builder::Init_PowerButtonState_timestamp();
}

}  // namespace px4

#endif  // PX4__MSG__DETAIL__POWER_BUTTON_STATE__BUILDER_HPP_
