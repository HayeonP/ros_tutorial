#include <ros_tutorial/class_pub.h>

ClassPub::ClassPub(){
    pub_ = nh_.advertise<std_msgs::Int32>("class_msg", 10);
}

void ClassPub::Run(){
    ros::Rate rate(10);

    int data = 0;
    while(nh_.ok()){
        msg_.data = data++;
        pub_.publish(msg_);
        ROS_INFO("Publish msg: %d", msg_.data);
        rate.sleep();
    }
}