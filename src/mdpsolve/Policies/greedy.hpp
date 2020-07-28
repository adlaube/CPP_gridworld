#ifndef GREEDY_HPP
#define GREEDY_HPP

#include "Policy.hpp"
#include "MDP.hpp"
#include <cstdint>


class Greedy : public Policy{


    public:
        void updatePolicy(MDP& mdp, std::vector<double> value_function, uint16_t max_iterations) override;
};

#endif