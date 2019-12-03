#include <ros/ros.h>
#include <std_msgs/Int32.h>

class ClassPub{
public:    
    ClassPub();
    void Run();
private:
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    std_msgs::Int32 msg_;
};