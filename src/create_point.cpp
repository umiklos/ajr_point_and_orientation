


#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"



int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("create_point");
    auto point_pub = node->create_publisher<geometry_msgs::msg::Point>("point", 1);
    auto point = std::make_shared<geometry_msgs::msg::Point>();
    point->x = 1.0;
    point->y = 2.0;
    point->z = 3.0;
    rclcpp::WallRate loop_rate(10);
    while (rclcpp::ok())
    {
        point_pub->publish(*point);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}