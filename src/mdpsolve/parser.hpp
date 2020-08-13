#ifndef PARSER_HPP
#define PARSER_HPP

#include "model.hpp"
#include "module.hpp"

class Model; // forward declaration

class Parser : public Module
{
      public:
	virtual ~Parser(){};
	virtual void parseFile(const std::string &filepath) = 0;
	Parser(Model &model) : Module(model) {}
	Parser() = delete;
};

#endif