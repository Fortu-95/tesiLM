// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from px4:msg/ParameterUpdate.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__PARAMETER_UPDATE__BUILDER_HPP_
#define PX4__MSG__DETAIL__PARAMETER_UPDATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "px4/msg/detail/parameter_update__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace px4
{

namespace msg
{

namespace builder
{

class Init_ParameterUpdate_custom_default
{
public:
  explicit Init_ParameterUpdate_custom_default(::px4::msg::ParameterUpdate & msg)
  : msg_(msg)
  {}
  ::px4::msg::ParameterUpdate custom_default(::px4::msg::ParameterUpdate::_custom_default_type arg)
  {
    msg_.custom_default = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4::msg::ParameterUpdate msg_;
};

class Init_ParameterUpdate_changed
{
public:
  explicit Init_ParameterUpdate_changed(::px4::msg::ParameterUpdate & msg)
  : msg_(msg)
  {}
  Init_ParameterUpdate_custom_default changed(::px4::msg::ParameterUpdate::_changed_type arg)
  {
    msg_.changed = std::move(arg);
    return Init_ParameterUpdate_custom_default(msg_);
  }

private:
  ::px4::msg::ParameterUpdate msg_;
};

class Init_ParameterUpdate_active
{
public:
  explicit Init_ParameterUpdate_active(::px4::msg::ParameterUpdate & msg)
  : msg_(msg)
  {}
  Init_ParameterUpdate_changed active(::px4::msg::ParameterUpdate::_active_type arg)
  {
    msg_.active = std::move(arg);
    return Init_ParameterUpdate_changed(msg_);
  }

private:
  ::px4::msg::ParameterUpdate msg_;
};

class Init_ParameterUpdate_export_count
{
public:
  explicit Init_ParameterUpdate_export_count(::px4::msg::ParameterUpdate & msg)
  : msg_(msg)
  {}
  Init_ParameterUpdate_active export_count(::px4::msg::ParameterUpdate::_export_count_type arg)
  {
    msg_.export_count = std::move(arg);
    return Init_ParameterUpdate_active(msg_);
  }

private:
  ::px4::msg::ParameterUpdate msg_;
};

class Init_ParameterUpdate_find_count
{
public:
  explicit Init_ParameterUpdate_find_count(::px4::msg::ParameterUpdate & msg)
  : msg_(msg)
  {}
  Init_ParameterUpdate_export_count find_count(::px4::msg::ParameterUpdate::_find_count_type arg)
  {
    msg_.find_count = std::move(arg);
    return Init_ParameterUpdate_export_count(msg_);
  }

private:
  ::px4::msg::ParameterUpdate msg_;
};

class Init_ParameterUpdate_set_count
{
public:
  explicit Init_ParameterUpdate_set_count(::px4::msg::ParameterUpdate & msg)
  : msg_(msg)
  {}
  Init_ParameterUpdate_find_count set_count(::px4::msg::ParameterUpdate::_set_count_type arg)
  {
    msg_.set_count = std::move(arg);
    return Init_ParameterUpdate_find_count(msg_);
  }

private:
  ::px4::msg::ParameterUpdate msg_;
};

class Init_ParameterUpdate_get_count
{
public:
  explicit Init_ParameterUpdate_get_count(::px4::msg::ParameterUpdate & msg)
  : msg_(msg)
  {}
  Init_ParameterUpdate_set_count get_count(::px4::msg::ParameterUpdate::_get_count_type arg)
  {
    msg_.get_count = std::move(arg);
    return Init_ParameterUpdate_set_count(msg_);
  }

private:
  ::px4::msg::ParameterUpdate msg_;
};

class Init_ParameterUpdate_instance
{
public:
  explicit Init_ParameterUpdate_instance(::px4::msg::ParameterUpdate & msg)
  : msg_(msg)
  {}
  Init_ParameterUpdate_get_count instance(::px4::msg::ParameterUpdate::_instance_type arg)
  {
    msg_.instance = std::move(arg);
    return Init_ParameterUpdate_get_count(msg_);
  }

private:
  ::px4::msg::ParameterUpdate msg_;
};

class Init_ParameterUpdate_timestamp
{
public:
  Init_ParameterUpdate_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ParameterUpdate_instance timestamp(::px4::msg::ParameterUpdate::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_ParameterUpdate_instance(msg_);
  }

private:
  ::px4::msg::ParameterUpdate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4::msg::ParameterUpdate>()
{
  return px4::msg::builder::Init_ParameterUpdate_timestamp();
}

}  // namespace px4

#endif  // PX4__MSG__DETAIL__PARAMETER_UPDATE__BUILDER_HPP_
