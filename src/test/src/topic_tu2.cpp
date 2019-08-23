#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>

ros::Subscriber sub;
ros::Publisher pub;

void test_cb
(const geometry_msgs::Twist& in_msg)
{
	std_msgs::Float64 out_msg;
	out_msg.data = in_msg.linear.x;
	pub.publish(out_msg);
	
	return;
}

int main
(int argc, char* argv[])
{
	ros::init(argc, argv, "topic_tu2");
	ros::NodeHandle nh;
	ros::Rate rate(10);
	
	sub = nh.subscribe("/cmd_vel", 10, test_cb);
	pub = nh.advertise<std_msgs::Float64>("/test",10);
	
	ros::spin();
	/*
	while(ros::ok()){
		ros::spinOnce();
		rate::sleep();
	}
	*/
	return 0;
}

