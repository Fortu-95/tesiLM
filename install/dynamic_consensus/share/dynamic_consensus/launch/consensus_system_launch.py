from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node




def launch_nodes(context, *args, **kwargs):
N = int(LaunchConfiguration('N').perform(context))
nodes = []


for i in range(N):
gen = Node(
package='dynamic_consensus',
executable='signal_generator_node',
name=f'signal_generator_{i}',
parameters=[{'node_id': i}],
output='screen'
)


con = Node(
package='dynamic_consensus',
executable='consensus_node',
name=f'consensus_node_{i}',
parameters=[{'node_id': i}],
output='screen'
)


nodes += [gen, con]


return nodes




def generate_launch_description():
return LaunchDescription([
DeclareLaunchArgument('N', default_value='8', description='Numero di nodi nella rete'),
OpaqueFunction(function=launch_nodes)
])
