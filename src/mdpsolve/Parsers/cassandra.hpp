#ifndef CASSANDRA_HPP
#define CASSANDRA_HPP

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../parser.hpp"

class Cassandra : public Parser
{
      public:
	void parseFile(const std::string &filepath) final;

	explicit Cassandra(Model &model) : Parser(model) {}

	Cassandra(const Cassandra &cassandra) = delete;
	Cassandra &operator=(const Cassandra &) = delete;

      private:
	void parseParams(std::ifstream &inputstream);
	void parseData(std::ifstream &inputstream);
	void parseTransitionMatrix(std::ifstream &inputstream,
				   const ACTION_ID action);
	void parseRewardMatrix(std::istringstream &iss);
};

#endif