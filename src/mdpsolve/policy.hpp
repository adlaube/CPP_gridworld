#ifndef POLICY_HPP
#define POLICY_HPP

#include <cstdint>
#include "model.hpp"
#include "evaluation.hpp"

class Evaluation; //forward declaration

class Policy{

    public:
        virtual void updatePolicy(const Model& mdp, const Evaluation& eval, uint16_t max_iterations) = 0;
        virtual ~Policy(){}

        virtual ACTION_ID getActionOfState(STATE_ID state_idx) = 0;

        Policy(STATE_ID num_of_states, ACTION_ID num_of_actions){ //assign since copy constructor is not implemented

            policy_mapping_ =  Array3d<double>(0,
                                                num_of_states,
                                                num_of_actions);                                           
        }

    protected:  
        Array3d<double> policy_mapping_; //is 2d but 3d causes almost no overhead      
};

#endif