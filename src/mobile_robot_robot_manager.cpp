#include "robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "robot_manager_inheritance/base_robot_manager.h"
#include <ros/ros.h>
#include <string>

MobileRobotRobotManager::MobileRobotRobotManager(ros::NodeHandle *nh)
    : RobotManagerBase(nh), odom_sub_{nh->subscribe(
                                odometry_topic_.c_str(), 10,
                                &MobileRobotRobotManager::odomemtryCallback,
                                this)} {
  ROS_INFO("Odometry subscriber created");
  robot_name_ = "Mobile robot";
  robot_location_ = "Next door";
}

MobileRobotRobotManager::MobileRobotRobotManager(ros::NodeHandle *nh,
                                                 std::string odom_topic)
    : RobotManagerBase(nh), odometry_topic_{odom_topic},
      odom_sub_{nh->subscribe(odometry_topic_.c_str(), 10,
                              &MobileRobotRobotManager::odomemtryCallback,
                              this)} {
  ROS_INFO("Odometry subscriber created");
  robot_name_ = "Mobile robot";
  robot_location_ = "Next door";
}

void MobileRobotRobotManager::odomemtryCallback(
    const nav_msgs::Odometry::ConstPtr &msg) {
  if (output_enabled_) {
    ROS_INFO("Position (x, y): %f, %f", msg->pose.pose.position.x,
             msg->pose.pose.position.y);
  }
}

void MobileRobotRobotManager::displayRobotDetails() {
    ROS_INFO("Robot name: %s", robot_name_.c_str());
    ROS_INFO("Robot location: %s", robot_location_.c_str());
    ROS_INFO("Battery charge level: %f", battery_charge_level_);
    ROS_INFO("Type of battery: %s", type_of_battery_.c_str());
}
