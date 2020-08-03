//acts as interface of lib, provides solve() function
//hier kommen argparse rein
//vllt noch nen besserer name für das file


#include "solve.hpp"

int run_mdpsolve(std::string filepath){

    Cassandra parser;
    MonteCarlo eval;
    PolicyIteration solver;

    Model newmdp;
    MODEL_SIZE sizes = newmdp.InitModel(filepath,parser);

    Greedy policy((STATE_ID) 1, (ACTION_ID) 1);

    solver.solve(newmdp,eval,policy,(uint16_t) 100);

    return 1;
}