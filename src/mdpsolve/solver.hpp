#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include "model.hpp"
#include "evaluation.hpp"
#include "policy.hpp"
#include <cstdint>

class Solver{  

    public:
        virtual void solve(const Model& model, const Evaluation& eval, const Policy& updater, const uint16_t max_number_of_iterations) = 0;
        virtual ~Solver(){};
        
};

#endif