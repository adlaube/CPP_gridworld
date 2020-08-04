#include "../factory.hpp"
#include "../constructor.hpp"
#include "../parser.hpp"
#include "cassandra.hpp"

class CassandraConstructor final: public Constructor<Parser>{

    public:
        CassandraConstructor(){
            Factory<Parser,Constructor<Parser>>& factory(Factory<Parser,Constructor<Parser>>::getInstance());
            factory.add("cassandra",this);
        }

        Cassandra* create(Model& model) override{
            return new Cassandra(model);
        }
 
};

//since C++17 - inline makes sure that this is save
static inline CassandraConstructor cassandra_constructor;

