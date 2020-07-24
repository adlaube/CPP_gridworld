//parse cmd line args and calls solve from mdpsolve lib
#include "mdpsolve/solve.hpp"
#include <string>

int main(){

    std::string filepath = "./data/4x3.95.POMDP";
    solve(filepath);
}