#include "tests/catch.hpp"
#include "solve.hpp"

TEST_CASE("test solving"){

        MdpSolve::Params params;
        
        params.filepath_        = "./data/4x3.95.POMDP";
        params.parser_          = "cassandra";
        params.eval_            = "montecarlo";
        params.policy_          = "greedy";
        params.solver_          = "policyiteration";
        params.iteration_cnt_   = 100;            

        std::unique_ptr<Policy> policy;
        policy = MdpSolve::solve_single_mdp(params);

        CHECK(policy->getActionOfState(0) == 2);
        CHECK(policy->getActionOfState(1) == 2);
        CHECK(policy->getActionOfState(2) == 2);
        CHECK(policy->getActionOfState(3) == 0);
        CHECK(policy->getActionOfState(4) == 0);
        CHECK(policy->getActionOfState(5) == 0);
        CHECK(policy->getActionOfState(6) == 0);
        CHECK(policy->getActionOfState(7) == 0);
        CHECK(policy->getActionOfState(8) == 2);
        CHECK(policy->getActionOfState(9) == 0);
        CHECK(policy->getActionOfState(10) == 3);


}