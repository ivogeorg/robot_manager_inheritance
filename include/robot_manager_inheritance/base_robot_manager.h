#ifndef BASE_ROBOT_MANAGER_H
#define BASE_ROBOT_MANAGER_H

#include <ros/ros.h>
#include <std_srvs/SetBool.h>

class RobotManagerBase {
  ros::ServiceServer config_output_server_;

protected:
  bool output_enabled_ = false;

public:
  RobotManagerBase() = default;
  RobotManagerBase(ros::NodeHandle *);
  ~RobotManagerBase() = default;

  bool serviceCallback(std_srvs::SetBool::Request &req,
                       std_srvs::SetBool::Response &res);
};

#endif