#include "ros/ros.h"
#include "error_listener.h"
int main(int argc, char **argv)
{
	error_listener err;
	err.RUN(argc, argv);
	return 0;
}