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

class Cassandra : public Parser{

    public:
        void parseFile (std::string filepath) final;

        Cassandra(Model& model):
            Parser(model){
            }

        Cassandra(const Cassandra& cassandra) = delete;
        Cassandra& operator= (const Cassandra&) = delete;                    

    private:
        void parseParams (std::ifstream& inputstream);
        void parseData(std::ifstream& inputstream);    
        void parseTransitionMatrix(std::ifstream& inputstream,const ACTION_ID action);
        void parseRewardMatrix(std::istringstream& iss);
        
};


#endif