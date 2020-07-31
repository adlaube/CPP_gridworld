#include "policyIteration.hpp"

void PolicyIteration::solve(const Model& model, const Evaluation& eval, const Policy& updater, const uint16_t max_number_of_iterations){

    policy_mapping_ = std::vector<STATE_ID>(model.num_of_states);
    value_function_ = std::vector<double>(model.num_of_states);

    while (iteration_cnt_ < max_number_of_iterations){
        eval.evaluatePolicy(model,value_function_,policy_mapping_,max_number_of_iterations);
        updater.updatePolicy(model,value_function_,policy_mapping_,max_number_of_iterations);    
        iteration_cnt_++;
    }
    print();
}

void PolicyIteration::print(){

    for (auto action : policy_mapping_){

        std::cout<<"ACTION: " << action << std::endl;
    }    

}