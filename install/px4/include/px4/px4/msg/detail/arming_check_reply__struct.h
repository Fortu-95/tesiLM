// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4:msg/ArmingCheckReply.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__ARMING_CHECK_REPLY__STRUCT_H_
#define PX4__MSG__DETAIL__ARMING_CHECK_REPLY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MESSAGE_VERSION'.
enum
{
  px4__msg__ArmingCheckReply__MESSAGE_VERSION = 0ul
};

/// Constant 'HEALTH_COMPONENT_INDEX_NONE'.
enum
{
  px4__msg__ArmingCheckReply__HEALTH_COMPONENT_INDEX_NONE = 0
};

/// Constant 'ORB_QUEUE_LENGTH'.
enum
{
  px4__msg__ArmingCheckReply__ORB_QUEUE_LENGTH = 4
};

// Include directives for member types
// Member 'events'
#include "px4/msg/detail/event__struct.h"

/// Struct defined in msg/ArmingCheckReply in the package px4.
typedef struct px4__msg__ArmingCheckReply
{
  /// time since system start (microseconds)
  uint64_t timestamp;
  uint8_t request_id;
  uint8_t registration_id;
  /// HEALTH_COMPONENT_INDEX_*
  uint8_t health_component_index;
  bool health_component_is_present;
  bool health_component_warning;
  bool health_component_error;
  /// whether arming is possible, and if it's a navigation mode, if it can run
  bool can_arm_and_run;
  uint8_t num_events;
  px4__msg__Event events[5];
  /// Mode requirements
  bool mode_req_angular_velocity;
  bool mode_req_attitude;
  bool mode_req_local_alt;
  bool mode_req_local_position;
  bool mode_req_local_position_relaxed;
  bool mode_req_global_position;
  bool mode_req_mission;
  bool mode_req_home_position;
  bool mode_req_prevent_arming;
  bool mode_req_manual_control;
} px4__msg__ArmingCheckReply;

// Struct for a sequence of px4__msg__ArmingCheckReply.
typedef struct px4__msg__ArmingCheckReply__Sequence
{
  px4__msg__ArmingCheckReply * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4__msg__ArmingCheckReply__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4__MSG__DETAIL__ARMING_CHECK_REPLY__STRUCT_H_
