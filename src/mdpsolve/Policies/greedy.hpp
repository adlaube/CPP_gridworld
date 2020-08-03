#ifndef GREEDY_HPP
#define GREEDY_HPP

#include "../policy.hpp"
#include "../model.hpp"
#include <cstdint>


class Greedy : public Policy{
    public:
        void updatePolicy(const Model& mdp, const Evaluation& eval, uint16_t max_iterations) override;
        ACTION_ID getActionOfState(STATE_ID state_idx) const override;

        Greedy(const Model& model): //call parent constructor
            Policy(model){
        }
};

#endif