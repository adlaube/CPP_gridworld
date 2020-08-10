#ifndef EVALUATION_HPP
#define EVALUATION_HPP

#include "model.hpp"
#include "policy.hpp"
#include <cstdint>

class Policy; //forward declaration

class Evaluation : public Module{
    public:
        virtual void evaluatePolicy(const Policy& policy) = 0;
        virtual double getValueOfState(STATE_ID state)const = 0;        
        virtual ~Evaluation(){};

        Evaluation(Model& model):
            Module(model),
            value_function_(std::vector<double>(model.num_of_states)){            
        }

    protected:
        std::vector<double> value_function_; 
};

#endif