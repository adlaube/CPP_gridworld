#include "policyIteration.hpp"

void PolicyIteration::solve(const Model& model,uint16_t max_number_of_iterations){

    policy_mapping = std::vector<STATE_ID>(model.num_of_states);
    value_function = std::vector<double>(model.num_of_states);
    eval.evaluatePolicy(model,value_function,policy_mapping,max_number_of_iterations);
    updater.updatePolicy(model,value_function,policy_mapping,max_number_of_iterations);
    
}