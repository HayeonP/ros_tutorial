#include <ros_tutorial/param_sub.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "param_sub");
    ParamSub param_sub;
    param_sub.Run();

    return 0;
}