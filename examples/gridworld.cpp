//parse cmd line args and calls solve from mdpsolve lib
#include <string>
#include "interface.hpp"


int main(){

    MdpSolve::Params params;
    std::string filepath = "./data/4x3.95.POMDP";
    MdpSolve::solve_single_mdp(params);
}