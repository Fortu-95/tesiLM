// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from px4:msg/RegisterExtComponentRequest.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__REGISTER_EXT_COMPONENT_REQUEST__FUNCTIONS_H_
#define PX4__MSG__DETAIL__REGISTER_EXT_COMPONENT_REQUEST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "px4/msg/rosidl_generator_c__visibility_control.h"

#include "px4/msg/detail/register_ext_component_request__struct.h"

/// Initialize msg/RegisterExtComponentRequest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * px4__msg__RegisterExtComponentRequest
 * )) before or use
 * px4__msg__RegisterExtComponentRequest__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__RegisterExtComponentRequest__init(px4__msg__RegisterExtComponentRequest * msg);

/// Finalize msg/RegisterExtComponentRequest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__RegisterExtComponentRequest__fini(px4__msg__RegisterExtComponentRequest * msg);

/// Create msg/RegisterExtComponentRequest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * px4__msg__RegisterExtComponentRequest__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
px4__msg__RegisterExtComponentRequest *
px4__msg__RegisterExtComponentRequest__create();

/// Destroy msg/RegisterExtComponentRequest message.
/**
 * It calls
 * px4__msg__RegisterExtComponentRequest__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__RegisterExtComponentRequest__destroy(px4__msg__RegisterExtComponentRequest * msg);

/// Check for msg/RegisterExtComponentRequest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__RegisterExtComponentRequest__are_equal(const px4__msg__RegisterExtComponentRequest * lhs, const px4__msg__RegisterExtComponentRequest * rhs);

/// Copy a msg/RegisterExtComponentRequest message.
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
px4__msg__RegisterExtComponentRequest__copy(
  const px4__msg__RegisterExtComponentRequest * input,
  px4__msg__RegisterExtComponentRequest * output);

/// Initialize array of msg/RegisterExtComponentRequest messages.
/**
 * It allocates the memory for the number of elements and calls
 * px4__msg__RegisterExtComponentRequest__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__RegisterExtComponentRequest__Sequence__init(px4__msg__RegisterExtComponentRequest__Sequence * array, size_t size);

/// Finalize array of msg/RegisterExtComponentRequest messages.
/**
 * It calls
 * px4__msg__RegisterExtComponentRequest__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__RegisterExtComponentRequest__Sequence__fini(px4__msg__RegisterExtComponentRequest__Sequence * array);

/// Create array of msg/RegisterExtComponentRequest messages.
/**
 * It allocates the memory for the array and calls
 * px4__msg__RegisterExtComponentRequest__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
px4__msg__RegisterExtComponentRequest__Sequence *
px4__msg__RegisterExtComponentRequest__Sequence__create(size_t size);

/// Destroy array of msg/RegisterExtComponentRequest messages.
/**
 * It calls
 * px4__msg__RegisterExtComponentRequest__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
void
px4__msg__RegisterExtComponentRequest__Sequence__destroy(px4__msg__RegisterExtComponentRequest__Sequence * array);

/// Check for msg/RegisterExtComponentRequest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_px4
bool
px4__msg__RegisterExtComponentRequest__Sequence__are_equal(const px4__msg__RegisterExtComponentRequest__Sequence * lhs, const px4__msg__RegisterExtComponentRequest__Sequence * rhs);

/// Copy an array of msg/RegisterExtComponentRequest messages.
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
px4__msg__RegisterExtComponentRequest__Sequence__copy(
  const px4__msg__RegisterExtComponentRequest__Sequence * input,
  px4__msg__RegisterExtComponentRequest__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PX4__MSG__DETAIL__REGISTER_EXT_COMPONENT_REQUEST__FUNCTIONS_H_
