#include <ros_tutorial/param_pub.h>

ParamPub::ParamPub(){
    pub_ = nh_.advertise<ros_tutorial::param_msg>("param_msg", 10);
}

void ParamPub::Run(){
    ros::Rate rate(10);

    nh_.param("/param_pub/int_param", int_data_, -1);
    if(!nh_.getParam("/param_pub/str_param", str_data_)){
        ROS_ERROR("Cannot get str_param!");
        exit(1);
    }

    ROS_WARN("Subscribe all params!");

    msg_.num = int_data_;
    msg_.str = str_data_;

    while(nh_.ok()){
        pub_.publish(msg_);
        ROS_INFO("Publish msg: %d / %s", int_data_, str_data_.c_str());
        rate.sleep();
    }
}