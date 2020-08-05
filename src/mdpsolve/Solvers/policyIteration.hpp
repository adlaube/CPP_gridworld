#ifndef POLICYITERATION_HPP
#define POLICYITERATION_HPP

#include <vector>
#include <iostream>
#include "../solver.hpp"
#include "../evaluation.hpp"
#include "../policy.hpp"
#include "../model.hpp"

class PolicyIteration : public Solver{

    public:
        void solve(Evaluation& eval, Policy& updater, const std::size_t max_number_of_iterations) override;
        PolicyIteration(Model& model):
            Solver(model){

            }

        PolicyIteration(const PolicyIteration& solver) = delete;
        PolicyIteration& operator= (const PolicyIteration&) = delete;      
};

#endif