// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from px4:msg/SensorAirflow.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__SENSOR_AIRFLOW__FUNCTIONS_H_
#define PX4__MSG__DETAIL__SENSOR_AIRFLOW__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "px4/msg/rosidl_generator_c__visibility_control.h"

#include "px4/msg/detail/sensor_airflow__struct.h"

/// Initialize msg/SensorAirflow message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * px4__msg__SensorAirflow
 * )) before or use
 * px4__msg__SensorAirflow__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__SensorAirflow__init(px4__msg__SensorAirflow * msg);

/// Finalize msg/SensorAirflow message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__SensorAirflow__fini(px4__msg__SensorAirflow * msg);

/// Create msg/SensorAirflow message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * px4__msg__SensorAirflow__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
px4__msg__SensorAirflow *
px4__msg__SensorAirflow__create();

/// Destroy msg/SensorAirflow message.
/**
 * It calls
 * px4__msg__SensorAirflow__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__SensorAirflow__destroy(px4__msg__SensorAirflow * msg);

/// Check for msg/SensorAirflow message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__SensorAirflow__are_equal(const px4__msg__SensorAirflow * lhs, const px4__msg__SensorAirflow * rhs);

/// Copy a msg/SensorAirflow message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__SensorAirflow__copy(
  const px4__msg__SensorAirflow * input,
  px4__msg__SensorAirflow * output);

/// Initialize array of msg/SensorAirflow messages.
/**
 * It allocates the memory for the number of elements and calls
 * px4__msg__SensorAirflow__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__SensorAirflow__Sequence__init(px4__msg__SensorAirflow__Sequence * array, size_t size);

/// Finalize array of msg/SensorAirflow messages.
/**
 * It calls
 * px4__msg__SensorAirflow__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__SensorAirflow__Sequence__fini(px4__msg__SensorAirflow__Sequence * array);

/// Create array of msg/SensorAirflow messages.
/**
 * It allocates the memory for the array and calls
 * px4__msg__SensorAirflow__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
px4__msg__SensorAirflow__Sequence *
px4__msg__SensorAirflow__Sequence__create(size_t size);

/// Destroy array of msg/SensorAirflow messages.
/**
 * It calls
 * px4__msg__SensorAirflow__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__SensorAirflow__Sequence__destroy(px4__msg__SensorAirflow__Sequence * array);

/// Check for msg/SensorAirflow message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__SensorAirflow__Sequence__are_equal(const px4__msg__SensorAirflow__Sequence * lhs, const px4__msg__SensorAirflow__Sequence * rhs);

/// Copy an array of msg/SensorAirflow messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__SensorAirflow__Sequence__copy(
  const px4__msg__SensorAirflow__Sequence * input,
  px4__msg__SensorAirflow__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PX4__MSG__DETAIL__SENSOR_AIRFLOW__FUNCTIONS_H_
