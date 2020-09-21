#include "ros/ros.h"
#include "check_message_alive.h"
int main(int argc, char **argv)
{
	check_message_alive diag_msg;
	diag_msg.RUN(argc, argv);
	return 0;
}