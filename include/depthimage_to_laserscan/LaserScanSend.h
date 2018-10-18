#include <nodelet/nodelet.h>
#include <math.h>
#include <sstream>
#include <sensor_msgs/LaserScan.h>
#include <ros/ros.h>

#include <cstring>
 
#include <TCPsend.h>

void chatterCallback(const sensor_msgs::LaserScan& scan)
{
  si->angle_min = scan->angle_min;
  si->angle_max = scan->angle_max;
  si->angle_increment = scan->angle_increment;

  memcpy(si->ranges,scan->ranges,sizeof(scan->ranges));

  TCPsend(si);

  ROS_INFO("chatterCallback of subSend is running");
}
