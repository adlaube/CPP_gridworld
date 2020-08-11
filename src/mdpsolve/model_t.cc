#include "tests/catch.hpp"
#include "model.hpp"

TEST_CASE("test model"){

        Model testmodel;
        REQUIRE_THROWS(testmodel.CheckConsistency());
        REQUIRE_THROWS(testmodel.SetArrays());

        testmodel.discount_rate = 0.5;
        testmodel.num_of_actions = 1;
        testmodel.num_of_states = 1;
        testmodel.optGoal = OPT_MAXIMIZE;

        REQUIRE_NOTHROW(testmodel.SetArrays());  
        REQUIRE_NOTHROW(testmodel.CheckConsistency());   
}