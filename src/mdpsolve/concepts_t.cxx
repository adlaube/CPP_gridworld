#include "constructor.hpp"
#include "factory.hpp"
#include "model.hpp"
#include "module.hpp"
#include "policy.hpp"

#include <type_traits>

class GoodModule : public Module
{
	GoodModule(Model &model) : Module(model) {}
};
class BadModule
{
	BadModule(int a) {}
};

int main()
{
	// POSITIVE TEST
	Factory<GoodModule>::getInstance();
	class TestPositive : public Constructor<GoodModule>
	{
	};

	// NEGATIVE TEST
	// Factory<BadModule>::getInstance();
	// class Test : public Constructor<BadModule>;
}
