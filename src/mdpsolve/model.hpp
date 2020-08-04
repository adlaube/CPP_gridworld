#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <cassert>
#include <vector>
#include <tuple>

#include "parser.hpp"
#include "array3d.hpp"

class Parser; //forward declaration

typedef std::size_t STATE_ID;
typedef std::size_t ACTION_ID;

using MODEL_SIZE = std::tuple<STATE_ID,ACTION_ID>;

#define DEF_ACTION_UNDEF    UINT16_MAX
#define DEF_ACTION_ALL      (DEF_ACTION_UNDEF - 1)

#define DEF_STATE_UNDEF     UINT16_MAX
#define DEF_STATE_ALL       (DEF_STATE_UNDEF - 1)

enum optimizationGoal{
    OPT_MAXIMIZE,
    OPT_MINIMIZE,
    OPT_UNDEFINED
};  


class Model{

    public:
        void SetArrays();
        void CheckConsistency(const std::string key);         

        Array3d<double> state_transition_matrix;
        Array3d<double> reward_matrix;    
        float discount_rate = 0;
        STATE_ID num_of_states = 0;
        ACTION_ID num_of_actions = 0;
        std::vector<std::string> action_strings; 
        enum optimizationGoal optGoal = OPT_UNDEFINED;

        //Model(const std::string filepath, const Parser& parser);
        //MODEL_SIZE InitModel(const std::string filepath, const Parser& parser);
        
};

#endif