#ifndef POLICY_HPP
#define POLICY_HPP

#include "model.hpp"
#include <cstdint>

class Policy{

    public:
        virtual void updatePolicy(Model* mdp, std::vector<double> value_function, uint16_t max_iterations) = 0;
        
};

#endif