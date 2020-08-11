#include "model.hpp"


void Model::setArrays(){

	state_transition_matrix =   Array3d<double>(num_of_actions,
								num_of_states,
								num_of_states);
	reward_matrix =             Array3d<double>(num_of_actions,
								num_of_states,
								num_of_states);
}

void Model::checkConsistency(){

	if((0 >= discount_rate || 1 < discount_rate) 	||
		(optGoal == OPT_UNDEFINED)            	||
		(num_of_states == 0)                   	||
		(num_of_actions == 0)){
		throw("model invalid");
		}
}