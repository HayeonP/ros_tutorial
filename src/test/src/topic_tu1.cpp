#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>

double linear_vel = -1.0;

void test_cb
(const geometry_msgs::Twist& in_msg)
{
	linear_vel = in_msg.linear.x;
	return;
}

int main
(int argc, char* argv[])
{
	ros::init(argc, argv, "topic_tu1");
	ros::NodeHandle nh;
	ros::Rate rate(10);
	
	ros::Subscriber sub = nh.subscribe("/cmd_vel", 10, test_cb);
	ros::Publisher pub = nh.advertise<std_msgs::Float64>("/test",10);
	
	while(ros::ok()){
		std_msgs::Float64 out_msg;
		out_msg.data = linear_vel;
		pub.publish(out_msg);
		ros::spinOnce();
		rate.sleep();
	}
	
	return 0;
}

