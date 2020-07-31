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
        void parseParams (std::string filepath, Model& model) const final;
        void parseData(std::string filepath, Model& model) const final;

    private:
        void parseTransitionMatrix(std::ifstream* inputstream,Model& model,const ACTION_ID action) const;
        void parseRewardMatrix(std::istringstream* iss,Model& model) const;
};


#endif