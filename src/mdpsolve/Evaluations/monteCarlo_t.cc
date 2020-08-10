#include "include/catch.hpp"
#include "Policies/greedy.hpp"
#include "monteCarlo.hpp"
#include "../model.hpp"

TEST_CASE("Test monte carlo"){

        Model testmodel;
        testmodel.num_of_actions                = 2;
        testmodel.num_of_states                 = 2;
        testmodel.discount_rate                 = 1;
        testmodel.state_transition_matrix       = Array3d<double> (2,2,2);
        testmodel.reward_matrix                 = Array3d<double> (2,2,2);
        testmodel.action_strings                = {"west","east"};
        testmodel.optGoal                       = OPT_MAXIMIZE;
        Greedy policy(testmodel);
        MonteCarlo eval(testmodel); 

        //ACTION 0 : west
        //ACTION 1 : east
        testmodel.state_transition_matrix(0,0,0) = 1; //stay in west
        testmodel.state_transition_matrix(0,0,1) = 0;
        testmodel.state_transition_matrix(0,1,0) = 1; //transfer to west
        testmodel.state_transition_matrix(0,1,1) = 0;

        testmodel.state_transition_matrix(1,0,0) = 0;
        testmodel.state_transition_matrix(1,0,1) = 1; //transfer to east
        testmodel.state_transition_matrix(1,1,0) = 0; //transfer to east
        testmodel.state_transition_matrix(1,1,1) = 1; //stay in east

        testmodel.reward_matrix(1,0,1) = 1; //going from west to east
        testmodel.reward_matrix(1,1,1) = 1; //staying east

        testmodel.reward_matrix(0,1,0) = -1; //going from east to west
        testmodel.reward_matrix(0,0,0) = -1; //staying west
        //policy says always take action #0
        //values are all 0
        eval.evaluatePolicy(policy);

        REQUIRE(eval.getValueOfState(0) == -1);
        REQUIRE(eval.getValueOfState(1) == -2);  

}