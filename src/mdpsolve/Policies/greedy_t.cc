#include "include/catch.hpp"
#include "greedy.hpp"
#include "Evaluations/monteCarlo.hpp"

TEST_CASE("Test policy iteration"){

        Model testmodel;
        testmodel.num_of_actions                = 2;
        testmodel.num_of_states                 = 2;
        testmodel.discount_rate                 = 1;
        testmodel.state_transition_matrix       = Array3d<double> (2,2,2);
        testmodel.reward_matrix                 = Array3d<double> (2,2,2);
        testmodel.action_strings                = {"west","east"};
        Greedy policy(testmodel);
        MonteCarlo eval(testmodel); 

        testmodel.state_transition_matrix(1,1,1) = 1; //stay in west
        testmodel.state_transition_matrix(1,1,2) = 0;
        testmodel.state_transition_matrix(1,2,1) = 1; //transfer to west
        testmodel.state_transition_matrix(1,2,2) = 0;

        testmodel.state_transition_matrix(2,1,1) = 0;
        testmodel.state_transition_matrix(2,1,2) = 1; //transfer to east
        testmodel.state_transition_matrix(2,2,2) = 1; //stay in east

        testmodel.reward_matrix(2,1,2) = 1; //only give reward when going from east to west

        //value function is 0 for all states
        policy.updatePolicy(eval);
        REQUIRE(greedy.getActionOfState(1))


}