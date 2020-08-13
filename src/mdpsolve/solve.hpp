#ifndef SOLVE_HPP
#define SOLVE_HPP

#include <memory>

#include "factory.hpp"
#include "interface.hpp"
#include "model.hpp"
#include "parser.hpp"
#include "policy.hpp"
#include "solver.hpp"

std::unique_ptr<Policy>
MdpSolve::solve_filebased_mdp(const MdpSolve::Params &params);
std::unique_ptr<Policy> solve_external_mdp(Model &model,
					   const MdpSolve::Params &params);

#endif