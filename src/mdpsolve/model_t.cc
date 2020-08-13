#include "model.hpp"
#include "tests/catch.hpp"

TEST_CASE("test model")
{
	Model testmodel;
	REQUIRE_THROWS(testmodel.checkConsistency());
	REQUIRE_THROWS(testmodel.setArrays());

	testmodel.discount_rate = 0.5;
	testmodel.num_of_actions = 1;
	testmodel.num_of_states = 1;
	testmodel.optGoal = OPT_MAXIMIZE;

	REQUIRE_NOTHROW(testmodel.setArrays());
	REQUIRE_NOTHROW(testmodel.checkConsistency());
}