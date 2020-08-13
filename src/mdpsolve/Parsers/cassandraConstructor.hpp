#ifndef CASSANDRA_CONSTRUCTOR_HPP
#define CASSANDRA_CONSTRUCTOR_HPP

#include "../constructor.hpp"
#include "../factory.hpp"
#include "../parser.hpp"
#include "cassandra.hpp"

using PARSER_FACTORY = Factory<Parser>;

class CassandraConstructor final : public Constructor<Parser>
{
      public:
	CassandraConstructor()
	{
		PARSER_FACTORY &factory(PARSER_FACTORY::getInstance());
		factory.add("cassandra", this);
	}

	Cassandra *create(Model &model) override
	{
		return new Cassandra(model);
	}
};

#endif
