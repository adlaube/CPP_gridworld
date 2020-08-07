#ifndef GREEDY_HPP
#define GREEDY_HPP

#include "../policy.hpp"

class Greedy : public Policy{
    public:
        void updatePolicy(const Model& mdp, const Evaluation& eval) override;
        void printPolicy() const override;
        ACTION_ID getActionOfState(STATE_ID state_idx) const override;

        explicit Greedy(Model& model): //call parent constructor
            Policy(model){
        }

        Greedy(const Greedy& greedy) = delete;
        Greedy& operator= (const Greedy&) = delete;         
};

#endif