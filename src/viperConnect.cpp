#include "rclcpp/rclcpp.hpp"
#include "viper_ui.h"
class viperConnect: public rclcpp::Node
{
private:
    /* data */
public:
    viperConnect(/* args */): Node("viper_test")
    {
        RCLCPP_INFO(this -> get_logger(), "Hello Viper");
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<viperConnect>();
    viper_ui ui;
    ui.detect_input();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}