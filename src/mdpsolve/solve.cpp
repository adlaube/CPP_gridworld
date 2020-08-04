#include "solve.hpp"

using PARSER_CONSTRUCTOR = Constructor<Parser>;
using PARSER_FACTORY = Factory<Parser,PARSER_CONSTRUCTOR>;

using POLICY_CONSTRUCTOR = Constructor<Policy>;
using POLICY_FACTORY = Factory<Policy,POLICY_CONSTRUCTOR>;

using EVALUATION_CONSTRUCTOR = Constructor<Evaluation>;
using EVALUATION_FACTORY = Factory<Evaluation,EVALUATION_CONSTRUCTOR>;

using SOLVER_CONSTRUCTOR = Constructor<Solver>;
using SOLVER_FACTORY = Factory<Solver,SOLVER_CONSTRUCTOR>; 

int MdpSolve::solve_single_mdp(const MdpSolve::Params& params){

    Model newmdp;
    auto parserFactory = PARSER_FACTORY::getInstance();
    Parser* parser = parserFactory.createInstance(params.parser_,newmdp);
    parser->parseFile(params.filepath_);

    POLICY_FACTORY policyFactory = POLICY_FACTORY::getInstance();
    Policy* policy = policyFactory.createInstance(params.policy_,newmdp);

    EVALUATION_FACTORY evaluationFactory = EVALUATION_FACTORY::getInstance();
    Evaluation* eval = evaluationFactory.createInstance(params.eval_,newmdp);    

    SOLVER_FACTORY solverFactory = SOLVER_FACTORY::getInstance();
    Solver* solver = solverFactory.createInstance(params.solver_,newmdp);        

    solver->solve(*eval,*policy,params.iteration_cnt_);

    return 1;
}