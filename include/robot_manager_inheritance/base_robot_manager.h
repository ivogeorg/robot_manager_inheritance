#ifndef BASE_ROBOT_MANAGER_H
#define BASE_ROBOT_MANAGER_H

#include <ros/ros.h>
#include <std_srvs/SetBool.h>

class RobotManagerBase {
  bool output_enabled_ = false;
  ros::ServiceServer config_output_server_;

public:
  RobotManagerBase() = default;
  RobotManagerBase(ros::NodeHandle *);
  ~RobotManagerBase() = default;

  bool serviceCallback(std_srvs::SetBool::Request &req,
                       std_srvs::SetBool::Response &res);
};

#endif