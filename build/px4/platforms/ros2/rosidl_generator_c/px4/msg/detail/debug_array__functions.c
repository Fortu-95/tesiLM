// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from px4:msg/DebugArray.idl
// generated code does not contain a copyright notice
#include "px4/msg/detail/debug_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
px4__msg__DebugArray__init(px4__msg__DebugArray * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  // id
  // name
  // data
  return true;
}

void
px4__msg__DebugArray__fini(px4__msg__DebugArray * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  // id
  // name
  // data
}

bool
px4__msg__DebugArray__are_equal(const px4__msg__DebugArray * lhs, const px4__msg__DebugArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // name
  for (size_t i = 0; i < 10; ++i) {
    if (lhs->name[i] != rhs->name[i]) {
      return false;
    }
  }
  // data
  for (size_t i = 0; i < 58; ++i) {
    if (lhs->data[i] != rhs->data[i]) {
      return false;
    }
  }
  return true;
}

bool
px4__msg__DebugArray__copy(
  const px4__msg__DebugArray * input,
  px4__msg__DebugArray * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  output->timestamp = input->timestamp;
  // id
  output->id = input->id;
  // name
  for (size_t i = 0; i < 10; ++i) {
    output->name[i] = input->name[i];
  }
  // data
  for (size_t i = 0; i < 58; ++i) {
    output->data[i] = input->data[i];
  }
  return true;
}

px4__msg__DebugArray *
px4__msg__DebugArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  px4__msg__DebugArray * msg = (px4__msg__DebugArray *)allocator.allocate(sizeof(px4__msg__DebugArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(px4__msg__DebugArray));
  bool success = px4__msg__DebugArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
px4__msg__DebugArray__destroy(px4__msg__DebugArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    px4__msg__DebugArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
px4__msg__DebugArray__Sequence__init(px4__msg__DebugArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  px4__msg__DebugArray * data = NULL;

  if (size) {
    data = (px4__msg__DebugArray *)allocator.zero_allocate(size, sizeof(px4__msg__DebugArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = px4__msg__DebugArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        px4__msg__DebugArray__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
px4__msg__DebugArray__Sequence__fini(px4__msg__DebugArray__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      px4__msg__DebugArray__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

px4__msg__DebugArray__Sequence *
px4__msg__DebugArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  px4__msg__DebugArray__Sequence * array = (px4__msg__DebugArray__Sequence *)allocator.allocate(sizeof(px4__msg__DebugArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = px4__msg__DebugArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
px4__msg__DebugArray__Sequence__destroy(px4__msg__DebugArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    px4__msg__DebugArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
px4__msg__DebugArray__Sequence__are_equal(const px4__msg__DebugArray__Sequence * lhs, const px4__msg__DebugArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!px4__msg__DebugArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
px4__msg__DebugArray__Sequence__copy(
  const px4__msg__DebugArray__Sequence * input,
  px4__msg__DebugArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(px4__msg__DebugArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    px4__msg__DebugArray * data =
      (px4__msg__DebugArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!px4__msg__DebugArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          px4__msg__DebugArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!px4__msg__DebugArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
