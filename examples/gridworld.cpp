//parse cmd line args and calls solve from mdpsolve lib
#include <string>
#include "interface.hpp"


int main(){

    MdpSolve::Params params;
    
    params.mdp_filepath_           = "./data/4x3.95.POMDP";
    params.module_parser_          = "cassandra";
    params.module_eval_            = "montecarlo";
    params.module_policy_          = "greedy";
    params.module_solver_          = "policyiteration";
    params.solver_iteration_cnt_   = 20;    
    
    std::unique_ptr<Policy> ptr = MdpSolve::solve_filebased_mdp(params);
}