#include "../factory.hpp"
#include "../constructor.hpp"
#include "greedy.hpp"

class GreedyConstructor final: public Constructor<Policy>{

    public:
        GreedyConstructor(){
            Factory<Policy,Constructor<Policy>>& factory(Factory<Policy,Constructor<Policy>>::getInstance());
            factory.add("greedy",this);
        }

        Greedy* create(const Model &model) const override{
            return new Greedy(model);
        }
};

