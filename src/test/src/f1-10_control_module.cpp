#include <control_module.h>

void ControlModule::twist_cb
(const geometry_msgs::TwistStamped& in_twist)
{
	twist_ = in_twist.twist;
	send_vesc_value();
	return;
}

void ControlModule::get_vesc_value()
{
	double twist_vel = twist_.linear.x;
	double twist_pos = twist_.angular.z;

}

void ControlModule::get_vesc_value_k()
{
	speed_ = twist_.linear.x * speed_to_erpm_gain + speed_to_erpm_offset;
	double angle = -1 * radian_to_degree(twist_.angular.z*0.1); //radian
	position_ = valMap(angle, -25.0, 25.0, 0.0, 1.0);
	if (position_ > 0.8) position_ = 0.8;
	else if (position_ < 0.2) position_ = 0.2;
}

void ControlModule::send_vesc_value()
{
	//if(isKeyboard_)
	get_vesc_value_k();
	//else
	//	get_vesc_value();

	std_msgs::Float64 velocity;
	std_msgs::Float64 position;
	velocity.data = speed_;
	position.data = position_;
	vel_pub_.publish(velocity);
	pos_pub_.publish(position);

	return;
}

double ControlModule::valMap
(double val, double in_min, double in_max, double out_min, double out_max)
{
	return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

double ControlModule::radian_to_degree
(double radian)
{
	return radian * 180 / PI;
}


void ControlModule::Run()
{
	nh_.param<bool>("keybaord", isKeyboard_, true);
	ROS_WARN("Keyboard : %s", isKeyboard_ ? "true" : "false");
	twist_sub_ = nh_.subscribe("/twist_cmd", 10, &ControlModule::twist_cb, this);
	vel_pub_ = nh_.advertise<std_msgs::Float64>("/commands/motor/speed", 10);
	pos_pub_ = nh_.advertise<std_msgs::Float64>("/commands/servo/position", 10);
	twist_ = geometry_msgs::Twist();

	ros::spin();
}