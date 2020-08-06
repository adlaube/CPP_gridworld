#include "monteCarlo.hpp"

void MonteCarlo::evaluatePolicyAtState(const Model& mdp, STATE_ID state, ACTION_ID selected_action )  {

    double V_current = value_function_[state];
    double transition_probability;
    STATE_ID num_of_states = mdp.num_of_states;    

    for (STATE_ID state_idx = 0;state_idx<num_of_states;state_idx++){
        transition_probability = mdp.state_transition_matrix(selected_action,state,state_idx);
        //Bellman equation
        V_current = V_current + transition_probability*(mdp.reward_matrix(selected_action,state,state_idx) + mdp.discount_rate *  value_function_[state_idx]);
    }
    value_function_[state] = V_current;
}


void MonteCarlo::evaluatePolicy(const Model& mdp, const Policy &policy) {
    
    STATE_ID num_of_states = mdp.num_of_states;
    ACTION_ID selected_action;
    
    for(STATE_ID state_idx = 0; state_idx < num_of_states;state_idx++)
    {
        selected_action = policy.getActionOfState(state_idx);
        evaluatePolicyAtState(mdp,state_idx,selected_action);
    }
}  

double MonteCarlo::getValueOfState(STATE_ID state) const{

    return value_function_[state];
}

