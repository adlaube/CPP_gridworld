#ifndef CASSANDRA_HPP
#define CASSANDRA_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

#include "../parser.hpp"

//Parser kann selbst setArrays und CheckConsistency aufrufen, müssen dann halt public sein

class Cassandra : public Parser{

    public:
        void parseParams (std::string filepath, Model& model) const final;
        void parseData(std::string filepath, Model& model) const final;

    private:
        void parseTransitionMatrix(std::ifstream* inputstream,Model& model) const;
        void parseRewardMatrix(std::istringstream* iss,Model& model) const;
};


#endif