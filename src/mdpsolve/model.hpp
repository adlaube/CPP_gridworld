#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <vector>

#include "array3d.hpp"

using STATE_ID = std::size_t;
using ACTION_ID = std::size_t;

#define DEF_ACTION_UNDEF SIZE_MAX
#define DEF_ACTION_ALL (DEF_ACTION_UNDEF - 1)

#define DEF_STATE_UNDEF SIZE_MAX
#define DEF_STATE_ALL (DEF_STATE_UNDEF - 1)

enum optimizationGoal { OPT_MAXIMIZE, OPT_MINIMIZE, OPT_UNDEFINED };

class Model {
    public:
	void setArrays();
	void checkConsistency();

	Array3d<double> state_transition_matrix;
	Array3d<double> reward_matrix;
	float discount_rate = 0;
	STATE_ID num_of_states = 0;
	ACTION_ID num_of_actions = 0;
	std::vector<std::string> action_strings;
	enum optimizationGoal optGoal = OPT_UNDEFINED;
};

#endif