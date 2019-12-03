#include <ros_tutorial/class_pub.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "class_pub");
    ClassPub class_pub;
    class_pub.Run();

    return 0;
}