#include "robot_manager_inheritance/base_robot_manager.h"
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

RobotManagerBase::RobotManagerBase(ros::NodeHandle *nh)
    : config_output_server_{nh->advertiseService(
          "robot_manager_output", &RobotManagerBase::serviceCallback, this)} {}

bool RobotManagerBase::serviceCallback(std_srvs::SetBool::Request &req,
                                  std_srvs::SetBool::Response &res) {

    return false;                                  
}