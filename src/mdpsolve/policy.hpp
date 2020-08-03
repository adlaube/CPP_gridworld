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

        virtual ACTION_ID getActionOfState(STATE_ID state_idx) const = 0;

        Policy (const Model& model) {//assign since copy constructor is not implemented
            policy_mapping_ =  Array3d<double>(1,
                                                model.num_of_actions,
                                                model.num_of_states);                                       
        }

    protected:  
        Array3d<double> policy_mapping_; //is 2d but 3d causes almost no overhead      
};

#endif