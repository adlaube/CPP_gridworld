//acts as interface of lib, provides solve() function
//hier kommen argparse rein

#include "solve.hpp"

int solve(std::string filepath){

    Cassandra ca;
    Parser* parser = (Parser *) &ca;
    
    Model newmdp(filepath,parser);

    return 1;
}