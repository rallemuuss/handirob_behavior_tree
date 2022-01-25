#include "handirob_behavior_tree/action_nodes/move_to.h"

MoveTo::MoveTo(const std::string& name, const BT::NodeConfiguration& config):
	SyncActionNode(name, config), nh_("~")
{	

}

BT::PortsList MoveTo::providedPorts()
{
	// This action has a single input port called "mood"
	// Any port must have a name. The type is optional.
    return{ BT::InputPort<std::string>("mood") };	// String to encode mood information.
}

BT::NodeStatus MoveTo::tick()
{
    BT::Optional<std::string> msg = getInput<std::string>("mood");
    // Check if optional is valid. If not, throw its error
    if (!msg)
    {
        throw BT::RuntimeError("missing required input [message]: ", msg.error() );
    }



	
    return BT::NodeStatus::SUCCESS;
}
