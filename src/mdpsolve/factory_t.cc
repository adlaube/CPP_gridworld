#include "include/catch.hpp"
#include "factory.hpp"
#include "policy.hpp"
#include "model.hpp"
#include "Policies/greedyConstructor.hpp"

 //make sure constructor is registered

TEST_CASE("Test Factory"){

    GreedyConstructor greedy_constructor; //register greedy
    Model testmodel;
    REQUIRE_THROWS(Factory<Policy>::getInstance().createInstance("testclass",testmodel));  
    REQUIRE_NOTHROW(Factory<Policy>::getInstance().createInstance("greedy",testmodel));

}


