#include <ros_tutorial/param_pub.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "param_pub");
    ParamPub param_pub;
    param_pub.Run();

    return 0;
}