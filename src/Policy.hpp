#ifndef POLICY_HPP
#define POLICY_HPP

#include "MDP.hpp"
#include <cstdint>

class Policy{

    public:
        virtual void updatePolicy(MDP& mdp, std::vector<double> value_function, uint16_t max_iterations) = 0;
        
};

#endif