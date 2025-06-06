// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4:msg/EstimatorSelectorStatus.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__ESTIMATOR_SELECTOR_STATUS__STRUCT_H_
#define PX4__MSG__DETAIL__ESTIMATOR_SELECTOR_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/EstimatorSelectorStatus in the package px4.
typedef struct px4__msg__EstimatorSelectorStatus
{
  /// time since system start (microseconds)
  uint64_t timestamp;
  uint8_t primary_instance;
  uint8_t instances_available;
  uint32_t instance_changed_count;
  uint64_t last_instance_change;
  uint32_t accel_device_id;
  uint32_t baro_device_id;
  uint32_t gyro_device_id;
  uint32_t mag_device_id;
  float combined_test_ratio[9];
  float relative_test_ratio[9];
  bool healthy[9];
  float accumulated_gyro_error[4];
  float accumulated_accel_error[4];
  bool gyro_fault_detected;
  bool accel_fault_detected;
} px4__msg__EstimatorSelectorStatus;

// Struct for a sequence of px4__msg__EstimatorSelectorStatus.
typedef struct px4__msg__EstimatorSelectorStatus__Sequence
{
  px4__msg__EstimatorSelectorStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4__msg__EstimatorSelectorStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4__MSG__DETAIL__ESTIMATOR_SELECTOR_STATUS__STRUCT_H_
