// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4:msg/SensorPreflightMag.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__SENSOR_PREFLIGHT_MAG__STRUCT_H_
#define PX4__MSG__DETAIL__SENSOR_PREFLIGHT_MAG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SensorPreflightMag in the package px4.
/**
  * Pre-flight sensor check metrics.
  * The topic will not be updated when the vehicle is armed
 */
typedef struct px4__msg__SensorPreflightMag
{
  /// time since system start (microseconds)
  uint64_t timestamp;
  /// maximum angle between magnetometer instance field vectors in radians.
  float mag_inconsistency_angle;
} px4__msg__SensorPreflightMag;

// Struct for a sequence of px4__msg__SensorPreflightMag.
typedef struct px4__msg__SensorPreflightMag__Sequence
{
  px4__msg__SensorPreflightMag * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4__msg__SensorPreflightMag__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4__MSG__DETAIL__SENSOR_PREFLIGHT_MAG__STRUCT_H_
