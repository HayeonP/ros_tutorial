#include <ros_tutorial/class_sub.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "class_sub");
    ClassSub class_sub;
    class_sub.Run();

    return 0;
}