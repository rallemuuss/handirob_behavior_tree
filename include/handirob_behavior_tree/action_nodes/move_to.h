#ifndef MOVE_TO_H
#define MOVE_TO_H

// ROS
#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>

// others
#include "behaviortree_cpp_v3/behavior_tree.h"

class MoveTo : public BT::SyncActionNode
{  
public:
    MoveTo(const std::string& name, const BT::NodeConfiguration& config);
    static BT::PortsList providedPorts();
    BT::NodeStatus tick() override; 

private:
    ros::NodeHandle nh_;

};


#endif // MOVE_TO_H