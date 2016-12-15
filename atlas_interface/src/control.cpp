#include<ros/ros.h>
#include<stdio.h>
#include<std_msgs/Int32.h>
#include<std_msgs/Float32.h>
#include<sandia_hand_msgs/RawTactile.h>
#include<sensor_msgs/JointState.h>
#include<osrf_msgs/JointCommands.h>
#include<atlas_msgs/AtlasCommand.h>
#include<atlas_msgs/AtlasSimInterfaceCommand.h>
#include<atlas_msgs/AtlasSimInterfaceState.h>
#include<atlas_msgs/AtlasState.h>

int main(int argc, char **argv)
{
float W_marble = 0.1;
float W_lost, W_cup = 1;
float g = 9.81;
float Fnet;
float Fref = (5*W_marble + W_cup)*g;
sleep(10);
ros::init(argc, argv, "control");
ros::NodeHandle nh;
ros::Publisher pub1 = nh.advertise<std_msgs::Int32>("/atlas/number_of_marbles",100);
ros::Publisher pub2 = nh.advertise<std_msgs::Float32>("/sandia_hands/r_hand/tactile_raw1",100);
std_msgs::Int32 n;
std_msgs::Float32 e;
sandia_hand_msgs::RawTactile a;
while (ros::ok())
{
for(int i = 10000; i > 0; i--)
{
Fnet = (i/10000*W_marble + W_cup)*g;
if(Fnet <= Fref)
        {
           W_lost = (Fref/10000 - Fnet)/g ;
           n.data = W_lost/W_marble;
           pub1.publish(n);
           e.data = 26500 + 7000*i/10000;
           ROS_INFO_STREAM(e.data);
           pub2.publish(e);
           sleep(0.1);
        }
}
ros::spinOnce();
}

}

