#ifndef GREEDY_HPP
#define GREEDY_HPP

#include "../policy.hpp"
#include <iomanip>
#include <limits>

class Greedy : public Policy
{
      public:
	void updatePolicy(const Evaluation &eval) override;
	void printPolicy() const override;
	ACTION_ID getActionOfState(STATE_ID state_idx) const override;

	explicit Greedy(Model &model)
	    : // call parent constructor
	      Policy(model)
	{
	}
};

#endif