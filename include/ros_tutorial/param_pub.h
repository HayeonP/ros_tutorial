#include <ros/ros.h>
#include <ros_tutorial/param_msg.h>

class ParamPub{
public:    
    ParamPub();
    void Run();
private:
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros_tutorial::param_msg msg_;
    int int_data_;
    std::string str_data_;
};