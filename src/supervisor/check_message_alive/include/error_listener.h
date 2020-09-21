#include <ros/ros.h>
#include <diagnostic_msgs/DiagnosticArray.h>
#include <diagnostic_msgs/DiagnosticStatus.h>

class error_listener
{
public:
    void diagnostics_callback(const diagnostic_msgs::DiagnosticArray::ConstPtr& msg);
    int RUN(int argc, char **argv);    
};