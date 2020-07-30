#include "policyIteration.hpp"

void PolicyIteration::solve(const Model& model){

    //LOOP
    eval->evaluatePolicy();
    updater->updatePolicy();
    
}