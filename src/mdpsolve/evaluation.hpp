#ifndef EVALUATION_HPP
#define EVALUATION_HPP

#include "MDP.hpp"
#include "Solver.hpp"
#include <cstdint>

class Evaluation{


    public:
        virtual void evaluatePolicy(MDP& mdp, std::vector<double> value_function, uint16_t max_iterations) = 0;
        
};

#endif