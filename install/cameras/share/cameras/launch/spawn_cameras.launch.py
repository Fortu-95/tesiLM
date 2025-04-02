import os
import tempfile

from launch import LaunchDescription
from launch.actions import ExecuteProcess

# Usa get_package_share_directory invece di FindPackageShare
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Trova il percorso di installazione del package "cameras"
    pkg_share = get_package_share_directory('cameras')
    # Costruisci il percorso della directory contenente i file SDF personalizzati
    model_directory = os.path.join(pkg_share, 'models', 'my_camera')
    
    # Definisci i nomi univoci per le telecamere
    camera_names = [
        "camera_1", "camera_2", "camera_3", "camera_4", "camera_5",
        "camera_6", "camera_7", "camera_8", "camera_9", "camera_10"
    ]
    
    # Definisci le pose per ogni telecamera (formato "x y z roll pitch yaw")
    poses = [
        "-2.5 -2.5 1 0 0 0",  # Camera 1
        "-1.5 -2.5 1 0 0 0",  # Camera 2
        "2.5 -2.5 1 0 0 0",   # Camera 3
        "2.5 -1.5 1 0 0 0",   # Camera 4
        "2.5 2.5 1 0 0 0",    # Camera 5
        "1.5 2.5 1 0 0 0",    # Camera 6
        "-2.5 2.5 1 0 0 0",   # Camera 7
        "-2.5 1.5 1 0 0 0",   # Camera 8
        "-2.5 -1.5 1 0 0 0",  # Camera 9
        "1.5 -2.5 1 0 0 0",   # Camera 10
    ]
    
    spawn_actions = []
    # Per ogni telecamera, assumiamo:
    # - camera_1 usa model1.sdf
    # - camera_2 usa model2.sdf, ecc.
    for i, (cam_name, pose_str) in enumerate(zip(camera_names, poses), start=1):
        # Costruisci il percorso assoluto del file SDF per questa telecamera
        sdf_file = os.path.join(model_directory, f"model{i}.sdf")
        # Dividi la stringa della posa nei suoi componenti
        pose_vals = pose_str.split()

        # Costruisci il comando per spawnare la telecamera
        cmd = [
            "ros2", "run", "gazebo_ros", "spawn_entity.py",
            "-entity", cam_name,
            "-file", sdf_file,
            "-x", pose_vals[0],
            "-y", pose_vals[1],
            "-z", pose_vals[2],
            "-R", pose_vals[3],
            "-P", pose_vals[4],
            "-Y", pose_vals[5]
        ]
        spawn_actions.append(
            ExecuteProcess(
                cmd=cmd,
                output="screen"
            )
        )
    
    ld = LaunchDescription()
    for action in spawn_actions:
        ld.add_action(action)
    
    return ld

if __name__ == '__main__':
    generate_launch_description()

