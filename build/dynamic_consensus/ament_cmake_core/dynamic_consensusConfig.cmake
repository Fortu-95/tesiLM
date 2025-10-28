# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dynamic_consensus_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dynamic_consensus_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dynamic_consensus_FOUND FALSE)
  elseif(NOT dynamic_consensus_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dynamic_consensus_FOUND FALSE)
  endif()
  return()
endif()
set(_dynamic_consensus_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dynamic_consensus_FIND_QUIETLY)
  message(STATUS "Found dynamic_consensus: 0.1.0 (${dynamic_consensus_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dynamic_consensus' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${dynamic_consensus_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dynamic_consensus_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dynamic_consensus_DIR}/${_extra}")
endforeach()
