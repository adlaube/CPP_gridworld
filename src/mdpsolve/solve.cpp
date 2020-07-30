//acts as interface of lib, provides solve() function
//hier kommen argparse rein

#include "solve.hpp"

int solve(std::string filepath){

    Cassandra ca;
    
    Model newmdp;
    newmdp.InitModel(filepath,ca);

    return 1;
}