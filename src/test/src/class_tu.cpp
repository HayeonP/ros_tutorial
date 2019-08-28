#include <class_tu.h>

void ClassTu::twist_cb
(const geometry_msgs::Twist& in_msg)
{
	std_msgs::Float64 out_msg;
	linear_vel_ = in_msg.linear.x;
	out_msg.data = linear_vel_;
	
	ROS_INFO("output : %lf", out_msg.data);
	ROS_WARN("output : %lf", out_msg.data);
	ROS_ERROR("output : %lf", out_msg.data);
	
	pub_.publish(out_msg);
	
	return;
}

void ClassTu::Run()
{
	pub_ = nh_.advertise<geometry_msgs::Twist>("/test_class", 10);
	// Very Very important
	sub_ = nh_.subscribe("/cmd_vel",10,&ClassTu::twist_cb, this);
	
	ros::spin();
	
	return;
}
