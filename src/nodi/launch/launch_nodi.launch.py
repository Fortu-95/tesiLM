from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='nodopacchetto',
            executable='nodo',
            name='nodo_0',
            arguments=['0']
        ),
        Node(
            package='nodopacchetto',
            executable='nodo',
            name='nodo_1',
            arguments=['1']
        ),
        Node(
            package='nodopacchetto',
            executable='nodo',
            name='nodo_2',
            arguments=['2']
        ),
        Node(
            package='nodopacchetto',
            executable='nodo',
            name='nodo_3',
            arguments=['3']
        ),
        Node(
            package='nodopacchetto',
            executable='nodo',
            name='nodo_4',
            arguments=['4']
        ),
        Node(
            package='nodopacchetto',
            executable='nodo',
            name='nodo_5',
            arguments=['5']
        ),
                Node(
            package='nodopacchetto',
            executable='nodo',
            name='nodo_6',
            arguments=['6']
        ),
        Node(
            package='nodopacchetto',
            executable='nodo',
            name='nodo_7',
            arguments=['7']
        )
    ])

