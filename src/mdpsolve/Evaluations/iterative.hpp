#ifndef ITERATIVE_HPP
#define ITERATIVE_HPP

#include "../evaluation.hpp"

class Iterative : public Evaluation{

    private:
        void evaluatePolicyAtState(STATE_ID state, ACTION_ID selected_action);
        public:
        void evaluatePolicy(const Policy &policy) override;
        double getValueOfState(STATE_ID state) const override;

        explicit Iterative(Model& model):
            Evaluation(model){
                
            }        

};

#endif