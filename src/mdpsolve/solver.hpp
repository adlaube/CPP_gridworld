#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "evaluation.hpp"
#include "model.hpp"
#include "module.hpp"
#include "policy.hpp"
#include <vector>

class Solver : public Module
{
      public:
	virtual void solve(Evaluation &eval, Policy &updater,
			   const std::size_t max_number_of_iterations) = 0;
	virtual ~Solver(){};

	Solver(Model &model) : Module(model) {}

      protected:
	std::size_t iteration_cnt_ = 0;
};

#endif