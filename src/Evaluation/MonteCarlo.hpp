#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include "Evaluation.hpp"
#include <random>
#include "MDP.hpp"

//use current policy until reach terminal state or until toggling has been detected
//exploring start - not possible for all environments

//nicht optimal die ganze Zeit getter aufzurufen vom MDP, Umbau auf Call by reference notwendig oder Alternative
//kein terminal state sondern max steps erreicht
class MonteCarlo : public Evaluation{

    private:
        std::mt19937 engine;
        std::uniform_int_distribution<unsigned int> distribution;
        MDP &mdp;

    public:
    MonteCarlo(MDP& new_mdp): mdp(new_mdp){
        distribution = std::uniform_int_distribution<unsigned int> {0,mdp.get_num_of_states()};
    }


    void evaluatePolicy(MDP& mdp, std::vector<double> value_function, uint16_t max_iterations) override;

    /*
        assumes a deterministic policy, this is also a constrain used by the MDP
    */

    void evaluatePolicyAtState(MDP& mdp, std::vector<double> value_function, STATE_ID state, std::vector<double> policy_mapping) ;
};

#endif