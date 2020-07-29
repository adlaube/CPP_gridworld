#ifndef CASSANDRA_HPP
#define CASSANDRA_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

#include "../parser.hpp"

class Cassandra : public Parser{

    public:
        void parseParams (std::string filepath, struct ModelParams* model_params) override;
        void parseData(std::string filepath, struct ModelData* model_data,struct ModelParams* model_params) override;

    private:
        void parseTransitionMatrix(std::ifstream* inputstream,struct ModelData* model_data,struct ModelParams* model_params);
        void parseRewardMatrix(std::istringstream* iss,struct ModelData* model_data,struct ModelParams* model_params);
};


#endif