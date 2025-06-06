// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4:msg/VehicleRatesSetpoint.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__VEHICLE_RATES_SETPOINT__STRUCT_H_
#define PX4__MSG__DETAIL__VEHICLE_RATES_SETPOINT__STRUCT_H_

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
  px4__msg__VehicleRatesSetpoint__MESSAGE_VERSION = 0ul
};

/// Struct defined in msg/VehicleRatesSetpoint in the package px4.
typedef struct px4__msg__VehicleRatesSetpoint
{
  /// time since system start (microseconds)
  uint64_t timestamp;
  /// body angular rates in FRD frame
  /// [rad/s] roll rate setpoint
  float roll;
  /// pitch rate setpoint
  float pitch;
  /// yaw rate setpoint
  float yaw;
  /// For clarification: For multicopters thrust_body[0] and thrust[1] are usually 0 and thrust[2] is the negative throttle demand.
  /// For fixed wings thrust_x is the throttle demand and thrust_y, thrust_z will usually be zero.
  /// Normalized thrust command in body NED frame [-1,1]
  float thrust_body[3];
  /// Reset roll/pitch/yaw integrals (navigation logic change)
  bool reset_integral;
} px4__msg__VehicleRatesSetpoint;

// Struct for a sequence of px4__msg__VehicleRatesSetpoint.
typedef struct px4__msg__VehicleRatesSetpoint__Sequence
{
  px4__msg__VehicleRatesSetpoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4__msg__VehicleRatesSetpoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4__MSG__DETAIL__VEHICLE_RATES_SETPOINT__STRUCT_H_
