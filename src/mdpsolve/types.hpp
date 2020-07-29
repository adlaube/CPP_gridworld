#ifndef TYPES_HPP
#define TYPES_HPP

#include <vector>
#include <cstdint>
#include <string>

#include "array3d.hpp"

typedef uint16_t STATE_ID;
typedef uint16_t ACTION_ID;
#define DEF_ACTION_UNDEF    UINT16_MAX
#define DEF_ACTION_ALL      (DEF_ACTION_UNDEF - 1)

#define DEF_STATE_UNDEF     UINT16_MAX
#define DEF_STATE_ALL       (DEF_STATE_UNDEF - 1)

enum optimizationGoal{
    OPT_MAXIMIZE,
    OPT_MINIMIZE,
    OPT_UNDEFINED
};  

struct ModelParams{
    float discount_rate = 0;
    STATE_ID num_of_states = 0;
    ACTION_ID num_of_actions = 0;
    std::vector<std::string> action_strings; 
    enum optimizationGoal optGoal = OPT_UNDEFINED;
};

struct ModelData{
    Array3d<double> state_transition_matrix;
    Array3d<double> reward_matrix; //flat matrix instead of 3d (action,start_state,next_state)
};


#endif
