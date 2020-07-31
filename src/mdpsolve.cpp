//parse cmd line args and calls solve from mdpsolve lib
#include <string>
#include "mdpsolve/solve.hpp"


int main(){

    std::string filepath = "./data/4x3.95.POMDP";
    run_mdpsolve(filepath);
}