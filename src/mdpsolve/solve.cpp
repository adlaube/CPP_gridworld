//acts as interface of lib, provides solve() function
//hier kommen argparse rein
//vllt noch nen besserer name für das file

#include "solve.hpp"


using POLICY_CONSTRUCTOR = Constructor<Policy>;
using PARSER_CONSTRUCTOR = Constructor<Parser>;

using POLICY_FACTORY = Factory<Policy,Constructor<Policy>>;
using EVALUATION_FACTORY = Factory<Evaluation,Constructor<Evaluation>>;
using PARSER_FACTORY = Factory<Parser,PARSER_CONSTRUCTOR>;
using SOLVER_FACTORY = Factory<Solver,Constructor<Solver>>;  



int run_mdpsolve(std::string filepath){

    //PARSER_CONSTRUCTOR::getInstance();

    //Cassandra parser;
    //PolicyIteration solver;
    Model newmdp;

    auto parserFactory = PARSER_FACTORY::getInstance();
    Parser* parser = parserFactory.createInstance("cassandra",newmdp);
    parser->parseFile(filepath);

    auto policyFactory = Factory<Policy,Constructor<Policy>>::getInstance();
    Policy* policy = policyFactory.createInstance("greedy",newmdp);

    auto evaluationFactory = Factory<Evaluation,Constructor<Evaluation>>::getInstance();
    Evaluation* eval = evaluationFactory.createInstance("montecarlo",newmdp);    

    //solver.solve(newmdp,*eval,*policy,(uint16_t) 100);

    return 1;
}