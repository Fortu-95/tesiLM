// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from px4:msg/EstimatorStatusFlags.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__ESTIMATOR_STATUS_FLAGS__FUNCTIONS_H_
#define PX4__MSG__DETAIL__ESTIMATOR_STATUS_FLAGS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "px4/msg/rosidl_generator_c__visibility_control.h"

#include "px4/msg/detail/estimator_status_flags__struct.h"

/// Initialize msg/EstimatorStatusFlags message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * px4__msg__EstimatorStatusFlags
 * )) before or use
 * px4__msg__EstimatorStatusFlags__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__EstimatorStatusFlags__init(px4__msg__EstimatorStatusFlags * msg);

/// Finalize msg/EstimatorStatusFlags message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__EstimatorStatusFlags__fini(px4__msg__EstimatorStatusFlags * msg);

/// Create msg/EstimatorStatusFlags message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * px4__msg__EstimatorStatusFlags__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
px4__msg__EstimatorStatusFlags *
px4__msg__EstimatorStatusFlags__create();

/// Destroy msg/EstimatorStatusFlags message.
/**
 * It calls
 * px4__msg__EstimatorStatusFlags__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__EstimatorStatusFlags__destroy(px4__msg__EstimatorStatusFlags * msg);

/// Check for msg/EstimatorStatusFlags message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__EstimatorStatusFlags__are_equal(const px4__msg__EstimatorStatusFlags * lhs, const px4__msg__EstimatorStatusFlags * rhs);

/// Copy a msg/EstimatorStatusFlags message.
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
px4__msg__EstimatorStatusFlags__copy(
  const px4__msg__EstimatorStatusFlags * input,
  px4__msg__EstimatorStatusFlags * output);

/// Initialize array of msg/EstimatorStatusFlags messages.
/**
 * It allocates the memory for the number of elements and calls
 * px4__msg__EstimatorStatusFlags__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__EstimatorStatusFlags__Sequence__init(px4__msg__EstimatorStatusFlags__Sequence * array, size_t size);

/// Finalize array of msg/EstimatorStatusFlags messages.
/**
 * It calls
 * px4__msg__EstimatorStatusFlags__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__EstimatorStatusFlags__Sequence__fini(px4__msg__EstimatorStatusFlags__Sequence * array);

/// Create array of msg/EstimatorStatusFlags messages.
/**
 * It allocates the memory for the array and calls
 * px4__msg__EstimatorStatusFlags__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
px4__msg__EstimatorStatusFlags__Sequence *
px4__msg__EstimatorStatusFlags__Sequence__create(size_t size);

/// Destroy array of msg/EstimatorStatusFlags messages.
/**
 * It calls
 * px4__msg__EstimatorStatusFlags__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__EstimatorStatusFlags__Sequence__destroy(px4__msg__EstimatorStatusFlags__Sequence * array);

/// Check for msg/EstimatorStatusFlags message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__EstimatorStatusFlags__Sequence__are_equal(const px4__msg__EstimatorStatusFlags__Sequence * lhs, const px4__msg__EstimatorStatusFlags__Sequence * rhs);

/// Copy an array of msg/EstimatorStatusFlags messages.
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
px4__msg__EstimatorStatusFlags__Sequence__copy(
  const px4__msg__EstimatorStatusFlags__Sequence * input,
  px4__msg__EstimatorStatusFlags__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PX4__MSG__DETAIL__ESTIMATOR_STATUS_FLAGS__FUNCTIONS_H_
