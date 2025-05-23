// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from px4:msg/ParameterSetValueRequest.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__PARAMETER_SET_VALUE_REQUEST__BUILDER_HPP_
#define PX4__MSG__DETAIL__PARAMETER_SET_VALUE_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "px4/msg/detail/parameter_set_value_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace px4
{

namespace msg
{

namespace builder
{

class Init_ParameterSetValueRequest_float_value
{
public:
  explicit Init_ParameterSetValueRequest_float_value(::px4::msg::ParameterSetValueRequest & msg)
  : msg_(msg)
  {}
  ::px4::msg::ParameterSetValueRequest float_value(::px4::msg::ParameterSetValueRequest::_float_value_type arg)
  {
    msg_.float_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4::msg::ParameterSetValueRequest msg_;
};

class Init_ParameterSetValueRequest_int_value
{
public:
  explicit Init_ParameterSetValueRequest_int_value(::px4::msg::ParameterSetValueRequest & msg)
  : msg_(msg)
  {}
  Init_ParameterSetValueRequest_float_value int_value(::px4::msg::ParameterSetValueRequest::_int_value_type arg)
  {
    msg_.int_value = std::move(arg);
    return Init_ParameterSetValueRequest_float_value(msg_);
  }

private:
  ::px4::msg::ParameterSetValueRequest msg_;
};

class Init_ParameterSetValueRequest_parameter_index
{
public:
  explicit Init_ParameterSetValueRequest_parameter_index(::px4::msg::ParameterSetValueRequest & msg)
  : msg_(msg)
  {}
  Init_ParameterSetValueRequest_int_value parameter_index(::px4::msg::ParameterSetValueRequest::_parameter_index_type arg)
  {
    msg_.parameter_index = std::move(arg);
    return Init_ParameterSetValueRequest_int_value(msg_);
  }

private:
  ::px4::msg::ParameterSetValueRequest msg_;
};

class Init_ParameterSetValueRequest_timestamp
{
public:
  Init_ParameterSetValueRequest_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ParameterSetValueRequest_parameter_index timestamp(::px4::msg::ParameterSetValueRequest::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_ParameterSetValueRequest_parameter_index(msg_);
  }

private:
  ::px4::msg::ParameterSetValueRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4::msg::ParameterSetValueRequest>()
{
  return px4::msg::builder::Init_ParameterSetValueRequest_timestamp();
}

}  // namespace px4

#endif  // PX4__MSG__DETAIL__PARAMETER_SET_VALUE_REQUEST__BUILDER_HPP_
