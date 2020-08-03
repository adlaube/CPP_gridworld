#include "policyIteration.hpp"

void PolicyIteration::solve(const Model& model, Evaluation& eval, Policy& updater, const uint16_t max_number_of_iterations){

    iteration_cnt_ = 0;
    while (iteration_cnt_ < max_number_of_iterations){
        eval.evaluatePolicy(model, updater,max_number_of_iterations);
        updater.updatePolicy(model, eval, max_number_of_iterations);    
        iteration_cnt_++;

        // PRINT STUFF
        // if(iteration_cnt_%10){
        //     int i = 0;
        //     for (auto action : updater.policy_mapping_){
        //         std::cout<<"STATE : " << i  << "  ACTION: " << model.action_strings[action] << " : "<< value_function_[i] << std::endl;
        //         i++;
        //     }       
        // }
                 
    }


}