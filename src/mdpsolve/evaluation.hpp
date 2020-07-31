#ifndef EVALUATION_HPP
#define EVALUATION_HPP

#include "model.hpp"
#include <cstdint>

class Evaluation{


    public:
        virtual void evaluatePolicy(const Model& mdp, std::vector<double>& value_function, std::vector<STATE_ID>& policy_mapping, uint16_t max_iterations) const = 0;
        virtual ~Evaluation(){};
};

#endif