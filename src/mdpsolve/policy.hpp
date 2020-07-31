#ifndef POLICY_HPP
#define POLICY_HPP

#include "model.hpp"
#include <cstdint>

class Policy{

    public:
        virtual void updatePolicy(const Model& mdp, std::vector<double>& value_function,std::vector<STATE_ID>& policy_mapping, uint16_t max_iterations) const = 0;
        
};

#endif