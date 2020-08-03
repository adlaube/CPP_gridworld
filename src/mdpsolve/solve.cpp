//acts as interface of lib, provides solve() function
//hier kommen argparse rein
//vllt noch nen besserer name für das file


#include "solve.hpp"

int run_mdpsolve(std::string filepath){

    Cassandra parser;
    MonteCarlo eval;
    PolicyIteration solver;

    Model newmdp;
    newmdp.InitModel(filepath,parser);

    auto factoryinstance = Factory<Policy,PolicyConstructor>::getInstance();
    Policy* policy = factoryinstance.createInstance("greedy",newmdp);



    solver.solve(newmdp,eval,*policy,(uint16_t) 100);

    return 1;
}