//acts as interface of lib, provides solve() function
//hier kommen argparse rein
//vllt noch nen besserer name für das file

#include "solve.hpp"

using PARSER_CONSTRUCTOR = Constructor<Parser>;
using POLICY_CONSTRUCTOR = Constructor<Policy>;
using EVALUATION_CONSTRUCTOR = Constructor<Evaluation>;
using SOLVER_CONSTRUCTOR = Constructor<Solver>;

using PARSER_FACTORY = Factory<Parser,PARSER_CONSTRUCTOR>;
using POLICY_FACTORY = Factory<Policy,POLICY_CONSTRUCTOR>;
using EVALUATION_FACTORY = Factory<Evaluation,EVALUATION_CONSTRUCTOR>;
using SOLVER_FACTORY = Factory<Solver,SOLVER_CONSTRUCTOR>; 

int MdpSolve::solve_single_mdp(const MdpSolve::Params& params){

    Model newmdp;
    std::string filepath = "whatever";
    auto parserFactory = PARSER_FACTORY::getInstance();
    Parser* parser = parserFactory.createInstance("cassandra",newmdp);
    parser->parseFile(filepath);

    auto policyFactory = POLICY_FACTORY::getInstance();
    Policy* policy = policyFactory.createInstance("greedy",newmdp);

    auto evaluationFactory = EVALUATION_FACTORY::getInstance();
    Evaluation* eval = evaluationFactory.createInstance("montecarlo",newmdp);    

    auto solverFactory = SOLVER_FACTORY::getInstance();
    Solver* solver = solverFactory.createInstance("policyiteration",newmdp);        

    solver->solve(*eval,*policy,(uint16_t) 100);

    return 1;
}