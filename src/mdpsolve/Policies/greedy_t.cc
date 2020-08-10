#include "include/catch.hpp"
#include "greedy.hpp"
#include "Evaluations/monteCarlo.hpp"

TEST_CASE("Test greedy policy"){

        Model testmodel;
        testmodel.num_of_actions                = 2;
        testmodel.num_of_states                 = 2;
        testmodel.discount_rate                 = 1;
        testmodel.state_transition_matrix       = Array3d<double> (2,2,2);
        testmodel.reward_matrix                 = Array3d<double> (2,2,2);
        testmodel.action_strings                = {"west","east"};
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
        testmodel.reward_matrix(1,1,1) = 1; //staying 

        testmodel.optGoal                       = OPT_MAXIMIZE;
        policy.updatePolicy(eval);
        REQUIRE(policy.getActionOfState(0) == 1);
        REQUIRE(policy.getActionOfState(1) == 1);

        testmodel.optGoal                       = OPT_MINIMIZE;
        policy.updatePolicy(eval);
        REQUIRE(policy.getActionOfState(0) == 0);
        REQUIRE(policy.getActionOfState(1) == 0);        

}