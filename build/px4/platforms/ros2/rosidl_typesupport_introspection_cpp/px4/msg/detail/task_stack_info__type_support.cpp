// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from px4:msg/TaskStackInfo.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "px4/msg/detail/task_stack_info__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace px4
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TaskStackInfo_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) px4::msg::TaskStackInfo(_init);
}

void TaskStackInfo_fini_function(void * message_memory)
{
  auto typed_message = static_cast<px4::msg::TaskStackInfo *>(message_memory);
  typed_message->~TaskStackInfo();
}

size_t size_function__TaskStackInfo__task_name(const void * untyped_member)
{
  (void)untyped_member;
  return 24;
}

const void * get_const_function__TaskStackInfo__task_name(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 24> *>(untyped_member);
  return &member[index];
}

void * get_function__TaskStackInfo__task_name(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 24> *>(untyped_member);
  return &member[index];
}

void fetch_function__TaskStackInfo__task_name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__TaskStackInfo__task_name(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__TaskStackInfo__task_name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__TaskStackInfo__task_name(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TaskStackInfo_message_member_array[3] = {
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(px4::msg::TaskStackInfo, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stack_free",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(px4::msg::TaskStackInfo, stack_free),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "task_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    24,  // array size
    false,  // is upper bound
    offsetof(px4::msg::TaskStackInfo, task_name),  // bytes offset in struct
    nullptr,  // default value
    size_function__TaskStackInfo__task_name,  // size() function pointer
    get_const_function__TaskStackInfo__task_name,  // get_const(index) function pointer
    get_function__TaskStackInfo__task_name,  // get(index) function pointer
    fetch_function__TaskStackInfo__task_name,  // fetch(index, &value) function pointer
    assign_function__TaskStackInfo__task_name,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TaskStackInfo_message_members = {
  "px4::msg",  // message namespace
  "TaskStackInfo",  // message name
  3,  // number of fields
  sizeof(px4::msg::TaskStackInfo),
  TaskStackInfo_message_member_array,  // message members
  TaskStackInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  TaskStackInfo_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TaskStackInfo_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TaskStackInfo_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace px4


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<px4::msg::TaskStackInfo>()
{
  return &::px4::msg::rosidl_typesupport_introspection_cpp::TaskStackInfo_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, px4, msg, TaskStackInfo)() {
  return &::px4::msg::rosidl_typesupport_introspection_cpp::TaskStackInfo_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
