#include <ros/ros.h>
#include <std_msgs/Int32.h>

void simple_node_cb(const std_msgs::Int32& msg){
    ROS_INFO("Subscribe msg : %d", msg.data);
}

int main(int argc, char* argv[]){
    ros::init(argc, argv, "simple_sub");
    ros::NodeHandle nh;
    ros::Rate rate(10);
    ros::Subscriber sub;

    sub = nh.subscribe("simple_node_msg", 10, simple_node_cb);

    while(ros::ok()){
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}