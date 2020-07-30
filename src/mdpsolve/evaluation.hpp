#ifndef EVALUATION_HPP
#define EVALUATION_HPP

#include "model.hpp"
#include "solver.hpp"
#include <cstdint>

class Evaluation{


    public:
        virtual void evaluatePolicy(Model& mdp, std::vector<double>& value_function, std::vector<STATE_ID>& policy_mapping, uint16_t max_iterations) = 0;
        
};

#endif