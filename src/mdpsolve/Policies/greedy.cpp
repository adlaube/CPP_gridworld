#include "greedy.hpp"
#include "greedyConstructor.hpp"

static GreedyConstructor greedy_constructor;

//iterate over all states, 
//iterate for each state over all possible actions, 
//iterate for each action over all possible following states

void Greedy::updatePolicy(const Evaluation& eval) {

    STATE_ID num_of_states = model_.num_of_states;
    ACTION_ID num_of_actions = model_.num_of_actions;
    double reward, state_probability,total_reward;

    for (STATE_ID current_state = 0;current_state<num_of_states;current_state++){

        double best_reward_value;
        ACTION_ID best_action_idx = 0;

        if(model_.optGoal == OPT_MAXIMIZE){
            best_reward_value = -1 * std::numeric_limits<double>::max();
        }
        if(model_.optGoal == OPT_MINIMIZE){
            best_reward_value = std::numeric_limits<double>::max();
        }
        
        for(ACTION_ID   action_idx = 0;
                        action_idx<num_of_actions;
                        action_idx++){
            total_reward = 0;
            for(STATE_ID state_idx = 0;state_idx<num_of_states;state_idx++){

                state_probability = model_.state_transition_matrix(action_idx,current_state,state_idx);
                reward = model_.reward_matrix(action_idx,current_state,state_idx);
                total_reward =  total_reward 
                                + state_probability * (reward + eval.getValueOfState(state_idx));
            }

            if((model_.optGoal == OPT_MAXIMIZE) && (total_reward > best_reward_value)){
                best_action_idx = action_idx;
                best_reward_value = total_reward;
            }

            if((model_.optGoal == OPT_MINIMIZE) && (total_reward < best_reward_value)){
                best_action_idx = action_idx;
                best_reward_value = total_reward;                
            }
             
        }
        //set best action as new action
        policy_mapping_(0,0,current_state) = best_action_idx;        
    }
}

ACTION_ID Greedy::getActionOfState(STATE_ID state_idx) const {

    return (ACTION_ID) policy_mapping_(0,0,state_idx);

}

void Greedy::printPolicy() const{

    
    for(STATE_ID state_idx = 0; state_idx<model_.num_of_states;state_idx++){
        ACTION_ID action_idx;
        action_idx = getActionOfState(state_idx);
        std::cout<<"STATE : " << state_idx  << "  ACTION: " << model_.action_strings[action_idx] << std::endl;

    }   
}

