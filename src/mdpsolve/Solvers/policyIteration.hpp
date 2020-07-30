#ifndef POLICYITERATION_HPP
#define POLICYITERATION_HPP

#include <vector>
#include "../solver.hpp"
#include "../evaluation.hpp"
#include "../policy.hpp"

class PolicyIteration: public Solver{

    public:
        void solve(const Model& model, uint16_t max_number_of_iterations) override;

        PolicyIteration(Evaluation* eval, Policy* updater);

    private:

        uint16_t iteration_cnt;
        Array3d<double> value_function;
        std::vector<int> policy_mapping;  
        void updatePolicy(MDP& mdp);
        void evaluatePolicy(MDP& mdp);    

};

#endif