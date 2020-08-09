#include "../factory.hpp"
#include "../constructor.hpp"
#include "../evaluation.hpp"
#include "monteCarlo.hpp"

//using EVALUATION_CONSTRUCTOR = Constructor<Evaluation>;
using EVALUATION_FACTORY = Factory<Evaluation>;

class MonteCarloConstructor final: public Constructor<Evaluation>{

    public:
        MonteCarloConstructor(){
            EVALUATION_FACTORY& factory(EVALUATION_FACTORY::getInstance());
            factory.add("montecarlo",this);
        }

        MonteCarlo* create(Model &model) override{
            return new MonteCarlo(model);
        }
};

