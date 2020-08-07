#include "include/catch.hpp"
#include "factory.hpp"
#include "policy.hpp"
#include "Policies/greedyConstructor.hpp"

 //make sure constructor is registered

TEST_CASE("Test Factory"){

    Model testmodel;
    testmodel.num_of_actions = 1;
    testmodel.num_of_states = 2;
    GreedyConstructor greedy;

    
    REQUIRE_THROWS(Factory<int,int>::getInstance().createInstance("testclass",testmodel));

    REQUIRE_THROWS(Factory<Policy,POLICY_CONSTRUCTOR>::getInstance().createInstance("testclass",testmodel));
    
    REQUIRE_NOTHROW(Factory<Policy,POLICY_CONSTRUCTOR>::getInstance().createInstance("greedy",testmodel));

}


