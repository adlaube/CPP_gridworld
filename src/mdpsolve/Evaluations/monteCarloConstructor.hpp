#include "../factory.hpp"
#include "../constructor.hpp"
#include "../evaluation.hpp"
#include "monteCarlo.hpp"

class MonteCarloConstructor final: public Constructor<Evaluation>{

    public:
        MonteCarloConstructor(){
            Factory<Evaluation,Constructor<Evaluation>>& factory(Factory<Evaluation,Constructor<Evaluation>>::getInstance());
            factory.add("montecarlo",this);
        }

        MonteCarlo* create(const Model &model) const override{
            return new MonteCarlo(model);
        }
};

