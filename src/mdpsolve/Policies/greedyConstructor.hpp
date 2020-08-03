#include "../factory.hpp"
#include "policyConstructor.hpp"
#include "greedy.hpp"

class GreedyConstructor final: public PolicyConstructor{

    public:
        GreedyConstructor(){
            Factory<Policy,PolicyConstructor>& factory(Factory<Policy,PolicyConstructor>::getInstance());
            factory.add("greedy",this);
        }

        Greedy* create(const Model &model) const override{
            return new Greedy(model);
        }
};

