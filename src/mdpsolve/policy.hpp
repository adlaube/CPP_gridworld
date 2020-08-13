#ifndef POLICY_HPP
#define POLICY_HPP

#include "evaluation.hpp"
#include "model.hpp"
#include "module.hpp"
#include <iostream>

class Evaluation; // forward declaration

class Policy : public Module {
    public:
	virtual ~Policy()
	{
	}
	virtual void updatePolicy(const Evaluation &eval) = 0;
	virtual void printPolicy() const = 0;
	virtual ACTION_ID getActionOfState(STATE_ID state_idx) const = 0;

	Policy(Model &model)
		: Module(model),
		  policy_mapping_(Array3d<double>(1, model.num_of_actions,
						  model.num_of_states))
	{
	}

    protected:
	Array3d<double> policy_mapping_; // is 2d but 3d causes almost no overhead
};

#endif