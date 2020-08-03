#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include <random>
#include "../evaluation.hpp"
#include "../policy.hpp"
#include "../model.hpp"

//use current policy until reach terminal state or until toggling has been detected
//exploring start - not possible for all environments

//nicht optimal die ganze Zeit getter aufzurufen vom MDP, Umbau auf Call by reference notwendig oder Alternative
//kein terminal state sondern max steps erreicht
class MonteCarlo : public Evaluation{

    private:
        //std::mt19937 engine;
        //std::uniform_int_distribution<unsigned long> distribution;
    void evaluatePolicyAtState(const Model& mdp, STATE_ID state, ACTION_ID selected_action);
    public:
    void evaluatePolicy(const Model& mdp, const Policy &policy, uint16_t max_iterations) override;
    double getValueOfState(STATE_ID state) const override;

    MonteCarlo(const Model& model):
        Evaluation(model){
            
        }

    
};

#endif