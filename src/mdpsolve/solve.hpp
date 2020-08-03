#ifndef SOLVE_HPP
#define SOLVE_HPP


#include <string>

//das sollte nicht notwendig sein über die factory 
#include "Environments/gridWorld.hpp"
#include "Evaluations/monteCarlo.hpp"
#include "Solvers/policyIteration.hpp"
#include "Policies/policyConstructor.hpp"
#include "policy.hpp"
#include "factory.hpp"
#include "Parsers/cassandra.hpp"
#include "model.hpp"

int run_mdpsolve(std::string filepath);

#endif

