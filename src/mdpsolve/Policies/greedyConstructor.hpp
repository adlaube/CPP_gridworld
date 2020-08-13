#include "../constructor.hpp"
#include "../factory.hpp"
#include "../policy.hpp"
#include "greedy.hpp"

using POLICY_FACTORY = Factory<Policy>;

class GreedyConstructor final : public Constructor<Policy>
{
      public:
	GreedyConstructor()
	{
		POLICY_FACTORY &factory(POLICY_FACTORY::getInstance());
		factory.add("greedy", this);
	}

	Greedy *create(Model &model) override { return new Greedy(model); }
};
