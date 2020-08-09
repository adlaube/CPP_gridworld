#include "include/catch.hpp"
#include "policyIteration.hpp"
#include "Policies/greedy.hpp"
#include "Evaluations/monteCarlo.hpp"

TEST_CASE("Test policy iteration"){

        Model testmodel;
        testmodel.num_of_actions                = 2;
        testmodel.num_of_states                 = 2;
        testmodel.discount_rate                 = 1;
        testmodel.state_transition_matrix       = Array3d<double> (2,2,2);
        testmodel.reward_matrix                 = Array3d<double> (2,2,2);
        testmodel.action_strings                = {"west","east"};
        PolicyIteration pi1(testmodel);
        MonteCarlo dummyeval(testmodel);
        Greedy dummypolicy(testmodel);

        pi1.solve(dummyeval,dummypolicy,100);
}