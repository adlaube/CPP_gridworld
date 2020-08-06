#ifndef CASSANDRA_CONSTRUCTOR_HPP
#define CASSANDRA_CONSTRUCTOR_HPP

#include "../factory.hpp"
#include "../constructor.hpp"
#include "../parser.hpp"
#include "cassandra.hpp"

using PARSER_CONSTRUCTOR = Constructor<Parser>;
using PARSER_FACTORY = Factory<Parser,PARSER_CONSTRUCTOR>;

class CassandraConstructor final: public PARSER_CONSTRUCTOR{

    public:
        CassandraConstructor(){
            PARSER_FACTORY& factory(PARSER_FACTORY::getInstance());
            factory.add("cassandra",this);
        }

        Cassandra* create(Model& model) override{
            return new Cassandra(model);
        }
 
};

#endif
