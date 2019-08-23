#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>

class ClassTu{
private:
	double linear_vel_ = -1.0;
	ros::NodeHandle nh_;
	ros::Publisher pub_;
	ros::Subscriber sub_;
private:
	void twist_cb(const geometry_msgs::Twist& in_msg);
public:
	ClassTu(){};
	void Run();
};
