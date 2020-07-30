#ifndef POLICYITERATION_HPP
#define POLICYITERATION_HPP

#include <array>
#include "../solver.hpp"
#include "../evaluation.hpp"
#include "../policy.hpp"

class PolicyIteration: public Solver{

    public:
        void solve(const Model& model, uint16_t max_number_of_iterations) override;

        PolicyIteration(const Evaluation& eval, const Policy& updater);

    private:

        Evaluation& eval;
        Policy& updater;
        uint16_t iteration_cnt = 0;
        std::vector<double> value_function; 
        std::vector<unsigned long> policy_mapping;  
};

#endif