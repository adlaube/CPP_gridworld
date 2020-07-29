#include "include/catch.hpp"

#include "cassandra.hpp"
#include "model.hpp"

TEST_CASE("Test Parser"){

    Cassandra parser;
    std::string filepath = "./data/4x3.95.POMDP";
    Model testmodel(filepath,parser);
}