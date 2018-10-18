#include <LaserScanSend.h>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "LaserScanSend");
  ros::NodeHandle lss;
  
  ros::Subscriber scanSub = lss.subscribe("scan", 1000, LaserScanSend::chatterCallback);
  ros::spin();

  return 0;
}