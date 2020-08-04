#ifndef SOLVE_HPP
#define SOLVE_HPP


#include <string>

//das sollte nicht notwendig sein über die factory 
#include "constructor.hpp"
#include "solver.hpp"
#include "policy.hpp"
#include "factory.hpp"
#include "model.hpp"

int run_mdpsolve(std::string filepath);

#endif

