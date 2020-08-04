#ifndef INTERFACE_HPP
#define INTERFACE_HPP


#include <string>
#include <cstdint>

namespace MdpSolve{

    struct Params{
        std::string filepath_;
        std::string parser_;
        std::string eval_;
        std::string policy_;
        std::string solver_;
        std::size_t iteration_cnt_;
    };



    int solve_single_mdp(const Params& params );


}



#endif

