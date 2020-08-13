#ifndef POLICYITERATION_HPP
#define POLICYITERATION_HPP

#include "../solver.hpp"
#include <iostream>
#include <vector>

class PolicyIteration : public Solver
{
      public:
	void solve(Evaluation &eval, Policy &updater,
		   const std::size_t max_number_of_iterations) override;
	explicit PolicyIteration(Model &model) : Solver(model) {}
};

#endif