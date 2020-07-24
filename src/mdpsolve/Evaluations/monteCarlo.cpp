#include "MonteCarlo.hpp"

void MonteCarlo::evaluatePolicyAtState(MDP& mdp, std::vector<double> value_function, STATE_ID state, std::vector<double> policy_mapping) {

    double V_new;
    STATE_ID num_of_states = mdp.get_num_of_states();
    uint16_t selected_action = policy_mapping[state];
    std::vector<double>::iterator iterStart = mdp.get_state_transition_matrix().begin() + (selected_action*(num_of_states*num_of_states) + state * num_of_states);
    std::vector<double>::iterator iterEnd = iterStart + num_of_states;  
    double transition_probability;
    STATE_ID state_idx = 0;

    for (auto pointer = iterStart;pointer<iterEnd;pointer++){
        transition_probability = *pointer;
        //Bellman equation
        V_new = V_new + transition_probability*(mdp.get_reward_structure()[selected_action*num_of_states] + mdp.get_discount_rate() *  value_function[state_idx]);
        state_idx++;
    }

    value_function[state] = V_new;

}


void MonteCarlo::evaluatePolicy(MDP& mdp, std::vector<double> value_function, uint16_t max_iterations){
    
    STATE_ID current_state;
    STATE_ID num_of_states = mdp.get_num_of_states();
            
    uint16_t iteration_cnt;
    
    while(iteration_cnt < max_iterations){

        for(STATE_ID state_idx = 0; state_idx < num_of_states;state_idx++)
        {
            evaluatePolicyAtState(mdp,value_function,state_idx);
        }

        iteration_cnt++;
    }
            
}    

