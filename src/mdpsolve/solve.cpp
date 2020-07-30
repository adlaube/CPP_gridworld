//acts as interface of lib, provides solve() function
//hier kommen argparse rein

#include "solve.hpp"

int run_mdpsolve(std::string filepath){

    Cassandra parser;
    MonteCarlo eval;
    Greedy policy;
    PolicyIteration solver(eval,policy);


    Model newmdp;
    newmdp.InitModel(filepath,parser);

    solver.solve(newmdp,(uint16_t) 100);
    


    return 1;
}