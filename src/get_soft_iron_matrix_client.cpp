#include "ros/ros.h"
#include "microstrain_3dm/GetSoftIronMatrix.h"
#include <cstdlib>


int main(int argc, char **argv){

  ros::init(argc, argv, "get_soft_iron_matrix");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<microstrain_3dm::GetSoftIronMatrix>("GetSoftIronMatrix");
  microstrain_3dm::GetSoftIronMatrix srv;

  if (client.call(srv))
  {
      if (srv.response.success)
      {
        ROS_INFO("success");
      }
  }
  else
  {
    ROS_INFO("Failed to call service");
  }
  return 0;
}
