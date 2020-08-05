#ifndef POLICY_HPP
#define POLICY_HPP

#include <cstdint>
#include <iostream>
#include "model.hpp"
#include "evaluation.hpp"

class Evaluation; //forward declaration

class Policy{

    public:
        virtual ~Policy(){}    
        virtual void updatePolicy(const Model& mdp, const Evaluation& eval, std::size_t max_iterations) = 0;
        virtual void printPolicy() const = 0;
        virtual ACTION_ID getActionOfState(STATE_ID state_idx) const = 0;

        Policy (const Model& model) :
            model_(model) {
            policy_mapping_ =  Array3d<double>(1,  //assign since copy constructor is not implemented
                                                model_.num_of_actions,
                                                model_.num_of_states);                                       
        }

    protected:  
        Array3d<double> policy_mapping_; //is 2d but 3d causes almost no overhead  
        const Model& model_;    
};

#endif