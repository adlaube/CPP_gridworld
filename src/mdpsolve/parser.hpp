#ifndef PARSER_HPP
#define PARSER_HPP

#include "model.hpp"

class Model; //forward declaration

class Parser{

    public:
        virtual ~Parser(){};
        virtual void parseFile(std::string filepath) = 0;
        Parser(Model& model):
            model_(model){

            }
        Parser() = delete;
    protected:
        Model& model_;       
};


#endif