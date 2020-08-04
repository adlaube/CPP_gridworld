#include "../factory.hpp"
#include "../constructor.hpp"
#include "../policy.hpp"
#include "greedy.hpp"

using POLICY_CONSTRUCTOR = Constructor<Policy>;
using POLICY_FACTORY = Factory<Policy,POLICY_CONSTRUCTOR>;  

class GreedyConstructor final: public Constructor<Policy>{

    public:
        GreedyConstructor(){
            Factory<Policy,Constructor<Policy>>& factory(Factory<Policy,Constructor<Policy>>::getInstance());
            factory.add("greedy",this);
        }

        Greedy* create(Model &model) override{
            return new Greedy(model);
        }
};

static inline GreedyConstructor greedy_constructor;

