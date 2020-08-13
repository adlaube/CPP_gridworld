#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "model.hpp"
#include "policy.hpp"
#include <memory>
#include <string>

namespace MdpSolve
{
struct Params {
	std::string mdp_filepath_;
	std::string module_parser_;
	std::string module_eval_;
	std::string module_policy_;
	std::string module_solver_;
	std::size_t solver_iteration_cnt_;
};
/*
    Solve mdp that is defined in a file on the filesystem
    */
std::unique_ptr<Policy> solve_filebased_mdp(const Params &params);
/*
    Solve mdp that has been defined by the application
    */
std::unique_ptr<Policy> solve_external_mdp(Model &model, const Params &params);
} // namespace MdpSolve

#endif
