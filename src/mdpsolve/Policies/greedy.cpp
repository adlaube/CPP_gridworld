#include "greedy.hpp"


//iterate over all states, 
//iterate for each state over all possible actions, 
//iterate for each action over all possible following states

void Greedy::updatePolicy(const Model& mdp, std::vector<double>& value_function,std::vector<STATE_ID>& policy_mapping, uint16_t max_iterations){

    uint16_t num_of_states = mdp.num_of_states;
    double reward, state_probability,total_reward, highest_reward;

    for (STATE_ID current_state = 0;current_state<num_of_states;current_state++){
        for(ACTION_ID action_idx = 0,best_action_idx=0;action_idx<mdp.num_of_actions;action_idx++){
            total_reward = 0;
            for(STATE_ID state_idx = 0;state_idx<num_of_states;state_idx++){

                state_probability = mdp.state_transition_matrix(action_idx,current_state,state_idx);
                reward = mdp.reward_matrix(action_idx,current_state,state_idx);
                total_reward = total_reward + state_probability * (reward + value_function[state_idx]);
            }
            //init highest reward with reward of first action
            if(action_idx==0){
                highest_reward = total_reward;
            }

            if(total_reward > highest_reward){
                best_action_idx = action_idx;
            }   
            //set best action as new action
            policy_mapping[current_state] = best_action_idx;                     
        }
    }
}

