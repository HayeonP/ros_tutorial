#include <ros_tutorial/param_sub.h>

ParamSub::ParamSub(){
    sub_ = nh_.subscribe("param_msg", 10, &ParamSub::param_node_cb, this);
}

void ParamSub::param_node_cb(const ros_tutorial::param_msg& msg){
    ROS_INFO("Subscribe msg : %d / %s", (int)msg.num, msg.str.c_str());
}

void ParamSub::Run(){
    ros::Rate rate(10);

    while(nh_.ok()){
        ros::spinOnce();
        rate.sleep();
    }
}