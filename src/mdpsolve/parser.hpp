#ifndef PARSER_HPP
#define PARSER_HPP

#include "types.hpp"

class Parser{

    public:
        virtual void parseParams(std::string filepath, struct ModelParams *model_params) = 0;
        virtual void parseData(std::string filepath, struct ModelData *model_data,struct ModelParams *model_params) = 0;
        virtual ~Parser() {};        
    
    private:

};


#endif