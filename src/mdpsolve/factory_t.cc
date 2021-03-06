#include "Policies/greedyConstructor.hpp"
#include "factory.hpp"
#include "model.hpp"
#include "policy.hpp"
#include "tests/catch.hpp"

// make sure constructor is registered

TEST_CASE("Test Factory")
{
	GreedyConstructor greedy_constructor; // register greedy
	Model testmodel;
	testmodel.num_of_actions = 2;
	testmodel.num_of_states = 2;
	REQUIRE_THROWS(Factory<Policy>::getInstance().createInstance(
		"testclass", testmodel));
	REQUIRE_NOTHROW(Factory<Policy>::getInstance().createInstance(
		"greedy", testmodel));
}
