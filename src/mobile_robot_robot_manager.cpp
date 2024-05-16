#include "robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "robot_manager_inheritance/base_robot_manager.h"
#include <ros/ros.h>
#include <string>

MobileRobotRobotManager::MobileRobotRobotManager(ros::NodeHandle *nh)
    : RobotManagerBase(nh), odom_sub_{nh->subscribe(
                                odometry_topic_.c_str(), 10,
                                &MobileRobotRobotManager::odomemtryCallback,
                                this)} {
  ROS_INFO("MobileRobotRobotManager created");
}

MobileRobotRobotManager::MobileRobotRobotManager(ros::NodeHandle *nh,
                                                 std::string odom_topic)
    : RobotManagerBase(nh), odometry_topic_{odom_topic},
      odom_sub_{nh->subscribe(odometry_topic_.c_str(), 10,
                              &MobileRobotRobotManager::odomemtryCallback,
                              this)} {
  ROS_INFO("MobileRobotRobotManager created");
}

void MobileRobotRobotManager::odomemtryCallback(
    const nav_msgs::Odometry::ConstPtr &msg) {
  if (output_enabled_) {
    ROS_INFO("Position (x, y): %f, %f", msg->pose.pose.position.x,
             msg->pose.pose.position.y);
  }
}
