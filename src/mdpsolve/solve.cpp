#include "solve.hpp"

using PARSER_FACTORY = Factory<Parser>;
using POLICY_FACTORY = Factory<Policy>;
using EVALUATION_FACTORY = Factory<Evaluation>;
using SOLVER_FACTORY = Factory<Solver>;

std::unique_ptr<Policy>
MdpSolve::solve_filebased_mdp(const MdpSolve::Params &params)
{
	Model newmdp;
	auto parser = PARSER_FACTORY::getInstance().createInstance(
	    params.module_parser_, newmdp);
	parser->parseFile(params.mdp_filepath_);

	auto policy = POLICY_FACTORY::getInstance().createInstance(
	    params.module_policy_, newmdp);
	auto eval = EVALUATION_FACTORY::getInstance().createInstance(
	    params.module_eval_, newmdp);
	auto solver = SOLVER_FACTORY::getInstance().createInstance(
	    params.module_solver_, newmdp);

	solver->solve(*eval, *policy, params.solver_iteration_cnt_);

	return policy;
}

std::unique_ptr<Policy>
MdpSolve::solve_external_mdp(Model &model, const MdpSolve::Params &params)
{
	auto policy = POLICY_FACTORY::getInstance().createInstance(
	    params.module_policy_, model);
	auto eval = EVALUATION_FACTORY::getInstance().createInstance(
	    params.module_eval_, model);
	auto solver = SOLVER_FACTORY::getInstance().createInstance(
	    params.module_solver_, model);

	solver->solve(*eval, *policy, params.solver_iteration_cnt_);

	return policy;
}