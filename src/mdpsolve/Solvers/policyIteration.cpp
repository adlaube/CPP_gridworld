#include "policyIteration.hpp"
#include "policyIterationConstructor.hpp"

static PolicyIterationConstructor policy_iteration_constructor;

void PolicyIteration::solve(Evaluation& eval, Policy& updater, const std::size_t max_number_of_iterations){

    iteration_cnt_ = 0;
    while (iteration_cnt_ < max_number_of_iterations){
        eval.evaluatePolicy(updater);
        updater.updatePolicy(eval);
        iteration_cnt_++;         
    }
    updater.printPolicy();
}