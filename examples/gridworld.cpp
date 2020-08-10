//parse cmd line args and calls solve from mdpsolve lib
#include <string>
#include "interface.hpp"


int main(){

    MdpSolve::Params params;
    
    params.filepath_        = "./data/4x3.95.POMDP";
    params.parser_          = "cassandra";
    params.eval_            = "montecarlo";
    params.policy_          = "greedy";
    params.solver_          = "policyiteration";
    params.iteration_cnt_   = 20;    
    
    std::unique_ptr<Policy> ptr = solve_single_mdp(params);
}