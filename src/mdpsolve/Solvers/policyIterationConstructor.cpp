#include "../factory.hpp"
#include "../constructor.hpp"
#include "../solver.hpp"
#include "policyIteration.hpp"

using SOLVER_CONSTRUCTOR = Constructor<Solver>;
using SOLVER_FACTORY = Factory<Solver,SOLVER_CONSTRUCTOR>;  

class PolicyIterationConstructor final: public SOLVER_CONSTRUCTOR{

    public:
        PolicyIterationConstructor(){
            SOLVER_FACTORY& factory(SOLVER_FACTORY::getInstance());
            factory.add("policyiteration",this);
        }

        PolicyIteration* create(Model &model) override{
            return new PolicyIteration(model);
        }
};

static inline PolicyIterationConstructor policy_iteration_constructor;

