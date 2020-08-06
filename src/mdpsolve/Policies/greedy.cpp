#include "greedy.hpp"


//iterate over all states, 
//iterate for each state over all possible actions, 
//iterate for each action over all possible following states

void Greedy::updatePolicy(const Model& mdp, const Evaluation& eval) {

    uint16_t num_of_states = mdp.num_of_states;
    double reward, state_probability,total_reward, highest_reward;

    for (STATE_ID current_state = 0;current_state<num_of_states;current_state++){
        for(ACTION_ID action_idx = 0,best_action_idx=0;action_idx<mdp.num_of_actions;action_idx++){
            total_reward = 0;
            for(STATE_ID state_idx = 0;state_idx<num_of_states;state_idx++){

                state_probability = mdp.state_transition_matrix(action_idx,current_state,state_idx);
                reward = mdp.reward_matrix(action_idx,current_state,state_idx);
                total_reward = total_reward + state_probability * (reward + eval.getValueOfState(state_idx));
            }
            //init highest reward with reward of first action
            if(action_idx==0){
                highest_reward = total_reward;
            }

            if(total_reward > highest_reward){
                best_action_idx = action_idx;
            }   
            //set best action as new action
            policy_mapping_(0,0,current_state) = best_action_idx;                     
        }
    }
}

ACTION_ID Greedy::getActionOfState(STATE_ID state_idx) const {

    return (ACTION_ID) policy_mapping_(0,0,state_idx);

}

void Greedy::printPolicy() const{

    ACTION_ID action_idx;
    for(STATE_ID state_idx = 0; state_idx<model_.num_of_states;state_idx++){

        action_idx = getActionOfState(state_idx);
        std::cout<<"STATE : " << state_idx  << "  ACTION: " << model_.action_strings[action_idx] << std::endl;

    }   
}

