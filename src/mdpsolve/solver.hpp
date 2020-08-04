#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include "model.hpp"
#include "evaluation.hpp"
#include "policy.hpp"
#include <cstdint>

class Solver{  

    public:
        virtual void solve(Evaluation& eval, Policy& updater, const uint16_t max_number_of_iterations) = 0;
        virtual ~Solver(){};

        Solver(const Model& model):
            model_(model){
        
            }

    protected:
        const Model& model_;
        uint16_t iteration_cnt_ = 0;
        
};

#endif