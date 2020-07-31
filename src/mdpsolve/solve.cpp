//acts as interface of lib, provides solve() function
//hier kommen argparse rein

#include "solve.hpp"

int run_mdpsolve(std::string filepath){

    Cassandra parser;
    MonteCarlo eval;
    Greedy policy;
    PolicyIteration solver;

    Model newmdp;
    newmdp.InitModel(filepath,parser);

    solver.solve(newmdp,eval,policy,(uint16_t) 100);

    return 1;
}