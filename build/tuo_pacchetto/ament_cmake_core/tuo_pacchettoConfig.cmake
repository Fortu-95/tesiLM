# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_tuo_pacchetto_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED tuo_pacchetto_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(tuo_pacchetto_FOUND FALSE)
  elseif(NOT tuo_pacchetto_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(tuo_pacchetto_FOUND FALSE)
  endif()
  return()
endif()
set(_tuo_pacchetto_CONFIG_INCLUDED TRUE)

# output package information
if(NOT tuo_pacchetto_FIND_QUIETLY)
  message(STATUS "Found tuo_pacchetto: 0.1.0 (${tuo_pacchetto_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'tuo_pacchetto' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${tuo_pacchetto_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(tuo_pacchetto_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${tuo_pacchetto_DIR}/${_extra}")
endforeach()
