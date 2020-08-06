#include "solve.hpp"

using PARSER_CONSTRUCTOR = Constructor<Parser>;
using PARSER_FACTORY = Factory<Parser,PARSER_CONSTRUCTOR>;

using POLICY_CONSTRUCTOR = Constructor<Policy>;
using POLICY_FACTORY = Factory<Policy,POLICY_CONSTRUCTOR>;

using EVALUATION_CONSTRUCTOR = Constructor<Evaluation>;
using EVALUATION_FACTORY = Factory<Evaluation,EVALUATION_CONSTRUCTOR>;

using SOLVER_CONSTRUCTOR = Constructor<Solver>;
using SOLVER_FACTORY = Factory<Solver,SOLVER_CONSTRUCTOR>; 

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