//acts as interface of lib, provides solve() function
//hier kommen argparse rein
//vllt noch nen besserer name für das file


#include "solve.hpp"

int run_mdpsolve(std::string filepath){

    const Cassandra parser;
    const MonteCarlo eval;
    const Greedy policy;
    PolicyIteration solver;

    Model newmdp;
    newmdp.InitModel(filepath,parser);

    solver.solve(newmdp,eval,policy,(uint16_t) 100);

    return 1;
}