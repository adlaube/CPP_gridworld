#ifndef EVALUATION_HPP
#define EVALUATION_HPP

#include "model.hpp"
#include "solver.hpp"
#include <cstdint>

class Evaluation{


    public:
        virtual void evaluatePolicy(const Model& model, std::vector<double> value_function, uint16_t max_iterations) = 0;
        
};

#endif