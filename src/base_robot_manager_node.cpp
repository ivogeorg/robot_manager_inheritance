#include "robot_manager_inheritance/base_robot_manager.h"
#include "ros/node_handle.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "base_robot_manager_node");

  ros::NodeHandle nh;
  RobotManagerBase rmi_node(&nh);

  return 0;
}