# pragma once

#define PCL_NO_PRECOMPILE
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/io/pcd_io.h>

#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <iomanip>

// #include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp>

#include <ros/ros.h>

class ParamServer
{
private:
    /* data */
public:
    ros::NodeHandle nh_;

    std::string kittiPath_;
    std::string savePath_;
    bool saveData_;
    
    ParamServer()
    {
        nh_.param<std::string>("vOdom/dataPath", kittiPath_, "/home/mgkim");   
        nh_.param<std::string>("vOdom/savePath", savePath_, "/home/mgkim");   
        nh_.param<bool>("vOdom/saveData", saveData_, false);
    }
};
