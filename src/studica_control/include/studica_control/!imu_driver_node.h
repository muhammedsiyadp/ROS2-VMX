#ifndef IMU_DRIVER_HPP_
#define IMU_DRIVER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include "VMXPi.h"
#include <studica_control/srv/set_data.hpp>
#include <std_msgs/msg/string.hpp>
#include "studica_control/device.h"

class ImuDriver : public Device {
public:
    ImuDriver(std::shared_ptr<VMXPi> vmx);
    void cmd(std::string params, std::shared_ptr<studica_control::srv::SetData::Response> response) override;

    void start_publishing();  // Method to start publishing
    void stop_publishing();   // Method to stop publishing

private:
    void publish_imu_data();
    void Spin();
    void publish_message();

    std::shared_ptr<VMXPi> vmx_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    
    int count_;
    bool is_publishing_;  // State variable to track if publishing is active
};

#endif // IMU_DRIVER_HPP_
