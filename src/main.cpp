#include <iostream>
#include "kittiIO.hpp"

int main(int argc, char **argv)
{

    ros::init(argc, argv, "vOdom");
    ROS_INFO("\033[1;32m----> KITTI Visual Odometry.\033[0m");

    kittiIO kittiIO;
    ros::spin();
    
    return 0;
}
