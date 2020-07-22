#ifndef POLICYITERATION_HPP
#define POLICYITERATION_HPP

#include <vector>
#include "Solver.hpp"
#include "MDP.hpp"
#include "Evaluation.hpp"
#include "Policy.hpp"

class PolicyIteration: public Solver{

    public:
        void solve(MDP& mdp, uint16_t max_number_of_iterations) override;

        PolicyIteration(Evaluation& eval, Policy& update);

    private:

        uint16_t iteration_cnt;
        Array3d<double> value_function;
        std::vector<int> policy_mapping;    
        MDP &mdp; //reference to the MDP to be solved, set in constructor, disable all other constructors
        void updatePolicy(MDP& mdp);
        void evaluatePolicy(MDP& mdp);    

};

#endif