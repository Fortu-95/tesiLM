import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess

def generate_launch_description():

    world_path = os.path.join(
        os.getenv('HOME'), 
        'ros2_ws/src/cameras/worlds',
        'gazebocameras.world' 
    )

    return LaunchDescription([
        ExecuteProcess(
            cmd=['gazebo', '--verbose', world_path],
            output='screen'
        )
    ])


