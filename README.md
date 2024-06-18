# ung_isl_ajr_point_and_orientation

ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/https://github.com/umiklos/ung_isl_ajr_point_and_orientation
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select ung_isl_ajr_point_and_orientation --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>


``` r
ros2 run ung_isl_ajr_point_and_orientation create_point 
```

``` r
ros2 run ung_isl_ajr_point_and_orientation create_orientation
```
## Graph

``` mermaid
graph LR;

gen([ /create_point]):::red --> sine

sine[ /point<br/>geometry_msgs/Point]:::light --> sum([ /create_orientation]):::red
sum --> out[ /pose<br/>geometry_msgs/Pose]:::light 


classDef light fill:#34aec5,stroke:#152742,stroke-width:2px,color:#152742  
classDef dark fill:#152742,stroke:#34aec5,stroke-width:2px,color:#34aec5
classDef white fill:#ffffff,stroke:#152742,stroke-width:2px,color:#152742
classDef red fill:#ef4638,stroke:#152742,stroke-width:2px,color:#fff
```
