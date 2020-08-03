#ifndef EVALUATION_HPP
#define EVALUATION_HPP

#include "model.hpp"
#include "policy.hpp"
#include <cstdint>

class Evaluation{


    public:
        virtual void evaluatePolicy(const Model& mdp, const Policy& policy, uint16_t max_iterations) = 0;
        virtual double getValueOfState(STATE_ID state)const = 0;        
        virtual ~Evaluation(){};

        Evaluation(STATE_ID num_of_states):
        value_function_(std::vector<double>(num_of_states)){            
        }

        Evaluation(){}

    protected:
        std::vector<double> value_function_; 
};

#endif