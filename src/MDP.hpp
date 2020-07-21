#ifndef MDP_HPP
#define MDP_HPP

#include <cstdint>
#include <vector>

typedef uint16_t STATE_ID;
typedef uint16_t ACTION_ID;

/*

maybe we make an MDP as singleton?
Than state::vector would make sense so it can grow shrink for the next mdp?
Start belief can be ignored because value because policy is optimal for every starting state
reward structure: action : start_state : end_state
R: <action> : <start-state> : <end-state> : <observation> %f
*/

//matrix name(sizeX, std::vector<double>(sizeY));

class MDP{

    private:
        std::vector<double> state_transition_matrix; //flat matrix instead of 3d (action,state,next_state)
        std::vector<double> reward_structure; //flat matrix instead of 3d (action,start_state,next_state)

        STATE_ID num_of_states;
        enum actions : unsigned int;
        float discount_rate;

        enum optimizationGoal{
            OPT_MAXIMIZE,
            OPT_MINIMIZE
        }; //maximum (reward) or minimum(cost)  

    public:
        STATE_ID get_num_of_states(){
            return num_of_states;
        }

        std::vector<double> get_state_transition_matrix(){
            return state_transition_matrix;
        }      
        
        std::vector<double> get_reward_structure(){
            return reward_structure;
        }            

        float get_discount_rate()
        {
            return discount_rate;
        }        
};

#endif