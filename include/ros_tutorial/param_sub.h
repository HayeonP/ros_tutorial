#include <ros/ros.h>
#include <ros_tutorial/param_msg.h>

class ParamSub{
public:    
    ParamSub();    
    void param_node_cb(const ros_tutorial::param_msg& msg);
    void Run();
private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_;
    ros_tutorial::param_msg msg_;
};