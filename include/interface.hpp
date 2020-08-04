#ifndef INTERFACE_HPP
#define INTERFACE_HPP


#include <string>

//das sollte nicht notwendig sein über die factory 
#include "constructor.hpp"
#include "solver.hpp"
#include "policy.hpp"
#include "factory.hpp"
#include "model.hpp"

namespace MdpSolve{

    struct Params{

        std::string filepath;
        std::string parser;
        std::string eval;
        std::string policy;
        std::string solver;
    };



    int solve_single_mdp(const Params& params );


}



#endif

