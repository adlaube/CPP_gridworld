#include "tests/catch.hpp"

#include "cassandra.hpp"
#include "model.hpp"

TEST_CASE("Test Parser"){

    double epsilon = 0.001;
    Model testmodel;
    Cassandra parser(testmodel);
    parser.parseFile("./data/4x3.95.POMDP");

    REQUIRE(testmodel.num_of_actions == 4);
    REQUIRE(testmodel.num_of_states == 11);
    REQUIRE(testmodel.optGoal == OPT_MAXIMIZE);
    REQUIRE(testmodel.action_strings[0] == "n");
    REQUIRE(testmodel.action_strings[1] == "s");
    REQUIRE(testmodel.action_strings[2] == "e");
    REQUIRE(testmodel.action_strings[3] == "w");
    REQUIRE(0.95-epsilon<testmodel.discount_rate);
    REQUIRE(0.95+epsilon>testmodel.discount_rate);
    REQUIRE(testmodel.state_transition_matrix.length_ == (4*11*11));
    REQUIRE(testmodel.reward_matrix.length_ == (4*11*11));

}