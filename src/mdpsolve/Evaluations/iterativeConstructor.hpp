#include "../factory.hpp"
#include "../constructor.hpp"
#include "../evaluation.hpp"
#include "iterative.hpp"

//using EVALUATION_CONSTRUCTOR = Constructor<Evaluation>;
using EVALUATION_FACTORY = Factory<Evaluation>;

class IterativeConstructor final: public Constructor<Evaluation>{

    public:
        IterativeConstructor(){
            EVALUATION_FACTORY& factory(EVALUATION_FACTORY::getInstance());
            factory.add("iterative",this);
        }

        Iterative* create(Model &model) override{
            return new Iterative(model);
        }
};

