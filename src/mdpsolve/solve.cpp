#include "solve.hpp"

using PARSER_FACTORY = Factory<Parser>;
using POLICY_FACTORY = Factory<Policy>;
using EVALUATION_FACTORY = Factory<Evaluation>;
using SOLVER_FACTORY = Factory<Solver>; 

std::unique_ptr<Policy> MdpSolve::solve_single_mdp(const MdpSolve::Params& params){

    Model newmdp;
    auto parser = PARSER_FACTORY::getInstance().createInstance(params.parser_,newmdp);
    parser->parseFile(params.filepath_);

    auto policy = POLICY_FACTORY::getInstance().createInstance(params.policy_,newmdp);
    auto eval = EVALUATION_FACTORY::getInstance().createInstance(params.eval_,newmdp);    
    auto solver = SOLVER_FACTORY::getInstance().createInstance(params.solver_,newmdp);        

    solver->solve(*eval,*policy,params.iteration_cnt_);

    return policy;
}