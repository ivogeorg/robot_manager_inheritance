#include "robot_manager_inheritance/base_robot_manager.h"
#include "robot_manager_inheritance/mobile_robot_robot_manager.h"
#include <ros/ros.h>


int main(int argc, char **argv) {
    ros::init(argc, argv, "mobile_robot_robot_manager_node");

    ros::NodeHandle nh;
    MobileRobotRobotManager mrrm_node(&nh);

    ros::spin();

    return 0;
}