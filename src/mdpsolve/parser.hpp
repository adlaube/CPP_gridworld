#ifndef PARSER_HPP
#define PARSER_HPP

#include "model.hpp"

class Model; //forward declaration

class Parser{

    public:
        virtual ~Parser(){};
        virtual void parseParams(std::string filepath, Model& model) const = 0;
        virtual void parseData(std::string filepath, Model& model) const = 0;
};


#endif