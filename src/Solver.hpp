#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include "MDP.hpp"
#include <cstdint>

class Solver{  

    public:
        virtual void solve(MDP& mdp, uint16_t max_number_of_iterations) = 0;
        
};

#endif