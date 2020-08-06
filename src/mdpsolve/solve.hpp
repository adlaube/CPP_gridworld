#ifndef SOLVE_HPP
#define SOLVE_HPP

#include <memory>

#include "interface.hpp"
#include "constructor.hpp"
#include "solver.hpp"
#include "policy.hpp"
#include "factory.hpp"
#include "model.hpp"

std::unique_ptr<Policy> MdpSolve::solve_single_mdp(const MdpSolve::Params& params);

#endif