#ifndef SOLVE_HPP
#define SOLVE_HPP


#include <string>

#include "Environments/gridWorld.hpp"
#include "Evaluations/monteCarlo.hpp"
#include "Solvers/policyIteration.hpp"
#include "Policies/greedy.hpp"
#include "Parsers/cassandra.hpp"
#include "model.hpp"

int run_mdpsolve(std::string filepath);

#endif

