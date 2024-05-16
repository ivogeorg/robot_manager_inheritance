#ifndef MOBILE_ROBOT_ROBOT_MANAGER_H
#define MOBILE_ROBOT_ROBOT_MANAGER_H

#include "robot_manager_inheritance/base_robot_manager.h"
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <string>

class MobileRobotRobotManager : public RobotManagerBase {
    std::string odometry_topic_ = "/robot1/odom";
    ros::Subscriber odom_sub_;
public:
    MobileRobotRobotManager() = default;
    MobileRobotRobotManager(ros::NodeHandle *);
    MobileRobotRobotManager(ros::NodeHandle *, std::string);
    ~MobileRobotRobotManager() = default;

    void odomemtryCallback(const nav_msgs::Odometry::ConstPtr &);
};





#endif