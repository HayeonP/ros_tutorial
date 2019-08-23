#include <class_tu.h>

int main
(int argc, char* argv[])
{
	ros::init(argc, argv, "test_class");
	ClassTu app;
	app.Run();
	
	return 0;
}
