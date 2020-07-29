//acts as interface of lib, provides solve() function
//hier kommen argparse rein

#include "solve.hpp"

int solve(std::string filepath){

    Parser* parser = Cassandra;
    
    Model newmdp(filepath,parser);

    return 1;
}