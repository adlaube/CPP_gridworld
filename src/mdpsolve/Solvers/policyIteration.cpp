#include "policyIteration.hpp"

void PolicyIteration::solve(Evaluation& eval, Policy& updater, const std::size_t max_number_of_iterations){

    iteration_cnt_ = 0;
    while (iteration_cnt_ < max_number_of_iterations){
        eval.evaluatePolicy(model_, updater);
        updater.updatePolicy(model_, eval);
        iteration_cnt_++;         
    }
    updater.printPolicy();
}