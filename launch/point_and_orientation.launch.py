from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ung_isl_ajr_point_and_orientation',
            executable='create_point',
        ),
        Node(
            package='ung_isl_ajr_point_and_orientation',
            executable='create_orientation',
        ),
    ])