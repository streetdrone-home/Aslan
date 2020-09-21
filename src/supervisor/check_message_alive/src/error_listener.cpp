#include <ros/ros.h>
#include <diagnostic_msgs/DiagnosticArray.h>
#include <diagnostic_msgs/DiagnosticStatus.h>
#include "error_listener.h"

void error_listener::diagnostics_callback(const diagnostic_msgs::DiagnosticArray::ConstPtr& msg)
{
    for(int topic = 0; topic < (msg->status).size(); topic++)
    {
        if(msg->status[topic].level == 2)
        {
            ROS_ERROR("Error in %s", msg->status[topic].name.c_str());
        }
    }
}

int error_listener::RUN(int argc, char **argv)
{
    ros::init(argc, argv, "read_diagnostics");

    ros::NodeHandle nh("~");
    ros::NodeHandle private_nh("~");
    
    ros::Subscriber aslan_diagnostics_sub = nh.subscribe<diagnostic_msgs::DiagnosticArray>("/aslan_diagnostics", 1, &error_listener::diagnostics_callback, this);
    while(ros::ok()) ros::spinOnce();
}