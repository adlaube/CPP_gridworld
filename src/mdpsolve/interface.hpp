#ifndef INTERFACE_HPP
#define INTERFACE_HPP


#include <string>

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

