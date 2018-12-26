/***************************************************************************
Copyright 2018 The Leishen Authors. All Rights Reserved                     /
                                                                            /
Licensed under the Apache License, Version 2.0 (the "License");             /
you may not use this file except in compliance with the License.            /
You may obtain a copy of the License at                                     /
                                                                            /
    http://www.apache.org/licenses/LICENSE-2.0                              /
                                                                            /
Unless required by applicable law or agreed to in writing, software         /
distributed under the License is distributed on an "AS IS" BASIS,           /
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.    /
See the License for the specific language governing permissions and         /
limitations under the License.                                              /
****************************************************************************/

#include <ros/ros.h>
#include <leishen_lslidar_c16_driver/lslidar_c16_driver.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "leishen_lslidar_c16_driver_node");
    ros::NodeHandle node;
    ros::NodeHandle private_nh("~");

    // start the driver
    apollo::drivers::lslidar_c16_driver::LslidarC16Driver driver(node, private_nh);
  if (!driver.initialize()) {
    ROS_ERROR("Cannot initialize lslidar driver...");
    return 0;
  }
    // loop until shut down or end of file
    while(ros::ok() && driver.polling()) {
        ros::spinOnce();

    }

    return 0;
}
