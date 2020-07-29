#include "greedy.hpp"


//iterate over all states, 
//iterate for each state over all possible actions, 
//iterate for each action over all possible following states

void Greedy::updatePolicy(MDP& mdp, std::vector<double> value_function, std::vector<double> policy_mapping){

    uint16_t num_of_states = mdp.get_num_of_states();
    uint16_t selected_action;
    double reward, state_probability,total_reward, highest_reward;
    ACTION_ID best_action;

    for (STATE_ID current_state = 0;current_state<num_of_states;current_state++){
        for(ACTION_ID action_idx = 0,best_action=0;action_idx<num_){
            total_reward = 0;
            for(STATE_ID state_idx = 0;state_idx<num_of_states;state_idx++){

                state_probability = mdp.get_state_transition_matrix()[action_idx*(num_of_states*num_of_states)+state_idx+num_of_states];
                reward = 0;
                total_reward = total_reward + state_probability * (reward +  
            }
            //init highest reward with reward of first action
            if(action_idx==0){
                highest_reward = total_reward;
            }

            if(total_reward > highest_reward){
                best_action = action_idx;
            }            
        }
        //set best action as new action
        policy_mapping[current_state] = action_idx;
        
    }
}

