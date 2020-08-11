#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include "../evaluation.hpp"

class MonteCarlo : public Evaluation{

    private:
        void evaluatePolicyAtState(STATE_ID state, ACTION_ID selected_action);
        public:
        void evaluatePolicy(const Policy &policy) override;
        double getValueOfState(STATE_ID state) const override;

        explicit MonteCarlo(Model& model):
            Evaluation(model){
                
            }        

};

#endif