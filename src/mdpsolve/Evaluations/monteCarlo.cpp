#include "monteCarlo.hpp"

void MonteCarlo::evaluatePolicyAtState(Model& mdp, std::vector<double>& value_function, STATE_ID state, ACTION_ID selected_action ) {

    double V_new,transition_probability;
    STATE_ID num_of_states = mdp.num_of_states;    

    for (STATE_ID state_idx = 0;state_idx<num_of_states;state_idx++){
        transition_probability = mdp.state_transition_matrix(selected_action,state,state_idx);
        //Bellman equation
        V_new = V_new + transition_probability*(mdp.reward_matrix(selected_action,state,state) + mdp.discount_rate *  value_function[state_idx]);
    }

    value_function[state] = V_new;

}


void MonteCarlo::evaluatePolicy(Model& mdp, std::vector<double>& value_function, std::vector<STATE_ID>& policy_mapping, uint16_t max_iterations){
    
    STATE_ID current_state;
    STATE_ID num_of_states = mdp.num_of_states;
    ACTION_ID selected_action;
            
    uint16_t iteration_cnt;
    
    while(iteration_cnt < max_iterations){

        for(STATE_ID state_idx = 0; state_idx < num_of_states;state_idx++)
        {
            selected_action = policy_mapping[state_idx];
            evaluatePolicyAtState(mdp,value_function,state_idx,selected_action);
        }

        iteration_cnt++;
    }
            
}    

