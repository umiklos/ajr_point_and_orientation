

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose.hpp"

class CreateOrientation : public rclcpp::Node
{
    public:
        CreateOrientation()
        : Node("create_orientation")
        {
            orientation_pub = this->create_publisher<geometry_msgs::msg::Pose>("pose", 10);
            subscription_ = this->create_subscription<geometry_msgs::msg::Point>(
                "point", 1, std::bind(&CreateOrientation::topic_callback, this, std::placeholders::_1));
        }

    private:
        void topic_callback(const geometry_msgs::msg::Point::SharedPtr msg) const
        {
            auto pose = std::make_shared<geometry_msgs::msg::Pose>();
            pose->position.x = msg->x;
            pose->position.y = msg->y;
            pose->position.z = msg->z;
            pose->orientation.x = 0.0;
            pose->orientation.y = 0.0;
            pose->orientation.z = 0.0;
            pose->orientation.w = 1.0;
            orientation_pub->publish(*pose);
        }
        rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr orientation_pub;
        rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr subscription_;
};
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CreateOrientation>());
  rclcpp::shutdown();
  return 0;
}

