#ifndef CASSANDRA_HPP
#define CASSANDRA_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "../parser.hpp"

//Parser kann selbst setArrays und CheckConsistency aufrufen, müssen dann halt public sein
//Umbau referenzen statt pointer

class Cassandra : public Parser{

    public:
        void parseFile (std::string filepath) final;

        Cassandra(Model& model):
            Parser(model){
            }

    private:
        void parseParams (std::string filepath);
        void parseData(std::string filepath);    
        void parseTransitionMatrix(std::ifstream* inputstream,const ACTION_ID action);
        void parseRewardMatrix(std::istringstream* iss);
        
};


#endif