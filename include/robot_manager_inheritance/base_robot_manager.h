#ifndef BASE_ROBOT_MANAGER_H
#define BASE_ROBOT_MANAGER_H

#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <string>

class RobotManagerBase {
  ros::ServiceServer config_output_server_;

protected:
  bool output_enabled_ = false;
  std::string robot_name_ = "Base robot name";
  std::string robot_location_ = "Base robot location";

public:
  RobotManagerBase() = default;
  RobotManagerBase(ros::NodeHandle *);
  ~RobotManagerBase() = default;

  virtual void displayRobotDetails() = 0;

  bool serviceCallback(std_srvs::SetBool::Request &req,
                       std_srvs::SetBool::Response &res);
};

#endif