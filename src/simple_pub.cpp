#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "simple_pub");
    ros::NodeHandle nh;
    ros::Rate rate(10);
    ros::Publisher pub;

    pub = nh.advertise<std_msgs::Int32>("simple_node_msg", 10);

    std_msgs::Int32 msg;
    int data = 0;

    while(ros::ok()){
        msg.data = data++;
        pub.publish(msg);
        ROS_INFO("Publish msg: %d", msg.data);
        rate.sleep();
    }

    return 0;
}