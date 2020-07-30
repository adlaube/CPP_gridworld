#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include "model.hpp"
#include <cstdint>

class Solver{  

    public:
        virtual void solve(const Model& model, uint16_t max_number_of_iterations) = 0;
        
};

#endif