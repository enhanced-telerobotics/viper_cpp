#include "rclcpp/rclcpp.hpp"
#include "viper_ui.h"

int main(int argc, char **argv)
{
    // Initialize ROS 2
    rclcpp::init(argc, argv);

    // Create a shared pointer to an instance of viper_ui
    auto node = std::make_shared<viper_ui>();

    // Spin up in a separate thread or before calling detect_input
    // to handle callbacks and keep ROS activities running
    std::thread ros_thread([&]() { rclcpp::spin(node); });

    // Call detect_input function which might be blocking or take time
    node->detect_input();

    // Shutdown ROS cleanly
    rclcpp::shutdown();

    // Join the thread to ensure clean exit
    ros_thread.join();

    return 0;
}