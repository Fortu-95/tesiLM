// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4:msg/RcChannels.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__RC_CHANNELS__STRUCT_H_
#define PX4__MSG__DETAIL__RC_CHANNELS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'FUNCTION_THROTTLE'.
enum
{
  px4__msg__RcChannels__FUNCTION_THROTTLE = 0
};

/// Constant 'FUNCTION_ROLL'.
enum
{
  px4__msg__RcChannels__FUNCTION_ROLL = 1
};

/// Constant 'FUNCTION_PITCH'.
enum
{
  px4__msg__RcChannels__FUNCTION_PITCH = 2
};

/// Constant 'FUNCTION_YAW'.
enum
{
  px4__msg__RcChannels__FUNCTION_YAW = 3
};

/// Constant 'FUNCTION_RETURN'.
enum
{
  px4__msg__RcChannels__FUNCTION_RETURN = 4
};

/// Constant 'FUNCTION_LOITER'.
enum
{
  px4__msg__RcChannels__FUNCTION_LOITER = 5
};

/// Constant 'FUNCTION_OFFBOARD'.
enum
{
  px4__msg__RcChannels__FUNCTION_OFFBOARD = 6
};

/// Constant 'FUNCTION_FLAPS'.
enum
{
  px4__msg__RcChannels__FUNCTION_FLAPS = 7
};

/// Constant 'FUNCTION_AUX_1'.
enum
{
  px4__msg__RcChannels__FUNCTION_AUX_1 = 8
};

/// Constant 'FUNCTION_AUX_2'.
enum
{
  px4__msg__RcChannels__FUNCTION_AUX_2 = 9
};

/// Constant 'FUNCTION_AUX_3'.
enum
{
  px4__msg__RcChannels__FUNCTION_AUX_3 = 10
};

/// Constant 'FUNCTION_AUX_4'.
enum
{
  px4__msg__RcChannels__FUNCTION_AUX_4 = 11
};

/// Constant 'FUNCTION_AUX_5'.
enum
{
  px4__msg__RcChannels__FUNCTION_AUX_5 = 12
};

/// Constant 'FUNCTION_AUX_6'.
enum
{
  px4__msg__RcChannels__FUNCTION_AUX_6 = 13
};

/// Constant 'FUNCTION_PARAM_1'.
enum
{
  px4__msg__RcChannels__FUNCTION_PARAM_1 = 14
};

/// Constant 'FUNCTION_PARAM_2'.
enum
{
  px4__msg__RcChannels__FUNCTION_PARAM_2 = 15
};

/// Constant 'FUNCTION_PARAM_3_5'.
enum
{
  px4__msg__RcChannels__FUNCTION_PARAM_3_5 = 16
};

/// Constant 'FUNCTION_KILLSWITCH'.
enum
{
  px4__msg__RcChannels__FUNCTION_KILLSWITCH = 17
};

/// Constant 'FUNCTION_TRANSITION'.
enum
{
  px4__msg__RcChannels__FUNCTION_TRANSITION = 18
};

/// Constant 'FUNCTION_GEAR'.
enum
{
  px4__msg__RcChannels__FUNCTION_GEAR = 19
};

/// Constant 'FUNCTION_ARMSWITCH'.
enum
{
  px4__msg__RcChannels__FUNCTION_ARMSWITCH = 20
};

/// Constant 'FUNCTION_FLTBTN_SLOT_1'.
enum
{
  px4__msg__RcChannels__FUNCTION_FLTBTN_SLOT_1 = 21
};

/// Constant 'FUNCTION_FLTBTN_SLOT_2'.
enum
{
  px4__msg__RcChannels__FUNCTION_FLTBTN_SLOT_2 = 22
};

/// Constant 'FUNCTION_FLTBTN_SLOT_3'.
enum
{
  px4__msg__RcChannels__FUNCTION_FLTBTN_SLOT_3 = 23
};

/// Constant 'FUNCTION_FLTBTN_SLOT_4'.
enum
{
  px4__msg__RcChannels__FUNCTION_FLTBTN_SLOT_4 = 24
};

/// Constant 'FUNCTION_FLTBTN_SLOT_5'.
enum
{
  px4__msg__RcChannels__FUNCTION_FLTBTN_SLOT_5 = 25
};

/// Constant 'FUNCTION_FLTBTN_SLOT_6'.
enum
{
  px4__msg__RcChannels__FUNCTION_FLTBTN_SLOT_6 = 26
};

/// Constant 'FUNCTION_ENGAGE_MAIN_MOTOR'.
enum
{
  px4__msg__RcChannels__FUNCTION_ENGAGE_MAIN_MOTOR = 27
};

/// Constant 'FUNCTION_PAYLOAD_POWER'.
enum
{
  px4__msg__RcChannels__FUNCTION_PAYLOAD_POWER = 28
};

/// Constant 'FUNCTION_FLTBTN_SLOT_COUNT'.
enum
{
  px4__msg__RcChannels__FUNCTION_FLTBTN_SLOT_COUNT = 6
};

/// Struct defined in msg/RcChannels in the package px4.
typedef struct px4__msg__RcChannels
{
  /// time since system start (microseconds)
  uint64_t timestamp;
  /// Timestamp of last valid RC signal
  uint64_t timestamp_last_valid;
  /// Scaled to -1..1 (throttle: 0..1)
  float channels[18];
  /// Number of valid channels
  uint8_t channel_count;
  /// Functions mapping
  int8_t function[29];
  /// Receive signal strength index
  uint8_t rssi;
  /// Control signal lost, should be checked together with topic timeout
  bool signal_lost;
  /// Number of dropped frames
  uint32_t frame_drop_count;
} px4__msg__RcChannels;

// Struct for a sequence of px4__msg__RcChannels.
typedef struct px4__msg__RcChannels__Sequence
{
  px4__msg__RcChannels * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4__msg__RcChannels__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4__MSG__DETAIL__RC_CHANNELS__STRUCT_H_
