// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from px4:msg/GimbalDeviceAttitudeStatus.idl
// generated code does not contain a copyright notice

#ifndef PX4__MSG__DETAIL__GIMBAL_DEVICE_ATTITUDE_STATUS__TRAITS_HPP_
#define PX4__MSG__DETAIL__GIMBAL_DEVICE_ATTITUDE_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "px4/msg/detail/gimbal_device_attitude_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace px4
{

namespace msg
{

inline void to_flow_style_yaml(
  const GimbalDeviceAttitudeStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: target_system
  {
    out << "target_system: ";
    rosidl_generator_traits::value_to_yaml(msg.target_system, out);
    out << ", ";
  }

  // member: target_component
  {
    out << "target_component: ";
    rosidl_generator_traits::value_to_yaml(msg.target_component, out);
    out << ", ";
  }

  // member: device_flags
  {
    out << "device_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.device_flags, out);
    out << ", ";
  }

  // member: q
  {
    if (msg.q.size() == 0) {
      out << "q: []";
    } else {
      out << "q: [";
      size_t pending_items = msg.q.size();
      for (auto item : msg.q) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: angular_velocity_x
  {
    out << "angular_velocity_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity_x, out);
    out << ", ";
  }

  // member: angular_velocity_y
  {
    out << "angular_velocity_y: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity_y, out);
    out << ", ";
  }

  // member: angular_velocity_z
  {
    out << "angular_velocity_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity_z, out);
    out << ", ";
  }

  // member: failure_flags
  {
    out << "failure_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.failure_flags, out);
    out << ", ";
  }

  // member: delta_yaw
  {
    out << "delta_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_yaw, out);
    out << ", ";
  }

  // member: delta_yaw_velocity
  {
    out << "delta_yaw_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_yaw_velocity, out);
    out << ", ";
  }

  // member: gimbal_device_id
  {
    out << "gimbal_device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.gimbal_device_id, out);
    out << ", ";
  }

  // member: received_from_mavlink
  {
    out << "received_from_mavlink: ";
    rosidl_generator_traits::value_to_yaml(msg.received_from_mavlink, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GimbalDeviceAttitudeStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }

  // member: target_system
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_system: ";
    rosidl_generator_traits::value_to_yaml(msg.target_system, out);
    out << "\n";
  }

  // member: target_component
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_component: ";
    rosidl_generator_traits::value_to_yaml(msg.target_component, out);
    out << "\n";
  }

  // member: device_flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.device_flags, out);
    out << "\n";
  }

  // member: q
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.q.size() == 0) {
      out << "q: []\n";
    } else {
      out << "q:\n";
      for (auto item : msg.q) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: angular_velocity_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity_x, out);
    out << "\n";
  }

  // member: angular_velocity_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity_y: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity_y, out);
    out << "\n";
  }

  // member: angular_velocity_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity_z, out);
    out << "\n";
  }

  // member: failure_flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "failure_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.failure_flags, out);
    out << "\n";
  }

  // member: delta_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_yaw, out);
    out << "\n";
  }

  // member: delta_yaw_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta_yaw_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.delta_yaw_velocity, out);
    out << "\n";
  }

  // member: gimbal_device_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gimbal_device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.gimbal_device_id, out);
    out << "\n";
  }

  // member: received_from_mavlink
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "received_from_mavlink: ";
    rosidl_generator_traits::value_to_yaml(msg.received_from_mavlink, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GimbalDeviceAttitudeStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace px4

namespace rosidl_generator_traits
{

[[deprecated("use px4::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const px4::msg::GimbalDeviceAttitudeStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  px4::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use px4::msg::to_yaml() instead")]]
inline std::string to_yaml(const px4::msg::GimbalDeviceAttitudeStatus & msg)
{
  return px4::msg::to_yaml(msg);
}

template<>
inline const char * data_type<px4::msg::GimbalDeviceAttitudeStatus>()
{
  return "px4::msg::GimbalDeviceAttitudeStatus";
}

template<>
inline const char * name<px4::msg::GimbalDeviceAttitudeStatus>()
{
  return "px4/msg/GimbalDeviceAttitudeStatus";
}

template<>
struct has_fixed_size<px4::msg::GimbalDeviceAttitudeStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<px4::msg::GimbalDeviceAttitudeStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<px4::msg::GimbalDeviceAttitudeStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PX4__MSG__DETAIL__GIMBAL_DEVICE_ATTITUDE_STATUS__TRAITS_HPP_
