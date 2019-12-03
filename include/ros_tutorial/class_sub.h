#include <ros/ros.h>
#include <std_msgs/Int32.h>

class ClassSub{
public:    
    ClassSub();    
    void class_node_cb(const std_msgs::Int32&);
    void Run();
private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_;
    std_msgs::Int32 msg_;
};