//acts as interface of lib, provides solve() function
//hier kommen argparse rein
//vllt noch nen besserer name für das file


#include "solve.hpp"

int run_mdpsolve(std::string filepath){

    Cassandra parser;
    PolicyIteration solver;
    Model newmdp;
    newmdp.InitModel(filepath,parser);

    auto policyFactory = Factory<Policy,Constructor<Policy>>::getInstance();
    Policy* policy = policyFactory.createInstance("greedy",newmdp);

    auto evaluationFactory = Factory<Evaluation,Constructor<Evaluation>>::getInstance();
    Evaluation* eval = evaluationFactory.createInstance("montecarlo",newmdp);    

    solver.solve(newmdp,*eval,*policy,(uint16_t) 100);

    return 1;
}