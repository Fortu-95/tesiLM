// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from px4:msg/OpenDroneIdArmStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "px4/msg/detail/open_drone_id_arm_status__rosidl_typesupport_introspection_c.h"
#include "px4/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "px4/msg/detail/open_drone_id_arm_status__functions.h"
#include "px4/msg/detail/open_drone_id_arm_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  px4__msg__OpenDroneIdArmStatus__init(message_memory);
}

void px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_fini_function(void * message_memory)
{
  px4__msg__OpenDroneIdArmStatus__fini(message_memory);
}

size_t px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__size_function__OpenDroneIdArmStatus__error(
  const void * untyped_member)
{
  (void)untyped_member;
  return 50;
}

const void * px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__get_const_function__OpenDroneIdArmStatus__error(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__get_function__OpenDroneIdArmStatus__error(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__fetch_function__OpenDroneIdArmStatus__error(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__get_const_function__OpenDroneIdArmStatus__error(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__assign_function__OpenDroneIdArmStatus__error(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__get_function__OpenDroneIdArmStatus__error(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_message_member_array[3] = {
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(px4__msg__OpenDroneIdArmStatus, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(px4__msg__OpenDroneIdArmStatus, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    50,  // array size
    false,  // is upper bound
    offsetof(px4__msg__OpenDroneIdArmStatus, error),  // bytes offset in struct
    NULL,  // default value
    px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__size_function__OpenDroneIdArmStatus__error,  // size() function pointer
    px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__get_const_function__OpenDroneIdArmStatus__error,  // get_const(index) function pointer
    px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__get_function__OpenDroneIdArmStatus__error,  // get(index) function pointer
    px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__fetch_function__OpenDroneIdArmStatus__error,  // fetch(index, &value) function pointer
    px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__assign_function__OpenDroneIdArmStatus__error,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_message_members = {
  "px4__msg",  // message namespace
  "OpenDroneIdArmStatus",  // message name
  3,  // number of fields
  sizeof(px4__msg__OpenDroneIdArmStatus),
  px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_message_member_array,  // message members
  px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_message_type_support_handle = {
  0,
  &px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_px4
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, px4, msg, OpenDroneIdArmStatus)() {
  if (!px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_message_type_support_handle.typesupport_identifier) {
    px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &px4__msg__OpenDroneIdArmStatus__rosidl_typesupport_introspection_c__OpenDroneIdArmStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
