#include "../factory.hpp"
#include "../constructor.hpp"
#include "../solver.hpp"
#include "policyIteration.hpp"

using SOLVER_FACTORY = Factory<Solver>;  

class PolicyIterationConstructor final: public Constructor<Solver>{

    public:
        PolicyIterationConstructor(){
            SOLVER_FACTORY& factory(SOLVER_FACTORY::getInstance());
            factory.add("policyiteration",this);
        }

        PolicyIteration* create(Model &model) override{
            return new PolicyIteration(model);
        }
};

