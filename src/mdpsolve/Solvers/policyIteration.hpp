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
        void solve(const Model& model, Evaluation& eval, Policy& updater, const uint16_t max_number_of_iterations) override;
    private:
        uint16_t iteration_cnt_ = 0;
};

#endif