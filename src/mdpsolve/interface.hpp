#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>
#include <memory>
#include "policy.hpp"

namespace MdpSolve{

    struct Params{
        std::string filepath_;
        std::string parser_;
        std::string eval_;
        std::string policy_;
        std::string solver_;
        std::size_t iteration_cnt_;
    };
    std::unique_ptr<Policy> solve_single_mdp(const Params& params );
}



#endif

