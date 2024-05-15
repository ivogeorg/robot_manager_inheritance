#ifndef MOBILE_ROBOT_ROBOT_MANAGER_H
#define MOBILE_ROBOT_ROBOT_MANAGER_H

#include "robot_manager_inheritance/base_robot_manager.h"
#include <ros/ros.h>

class MobileRobotRobotManager : public RobotManagerBase {
public:
    MobileRobotRobotManager() = default;
    MobileRobotRobotManager(ros::NodeHandle *);
    ~MobileRobotRobotManager() = default;
};





#endif