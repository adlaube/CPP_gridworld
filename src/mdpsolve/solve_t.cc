#include "tests/catch.hpp"
#include "solve.hpp"

TEST_CASE("test solving from file"){

        MdpSolve::Params params;
        
        params.mdp_filepath_        = "./data/4x3.95.POMDP";
        params.module_parser_          = "cassandra";
        params.module_eval_            = "iterative";
        params.module_policy_          = "greedy";
        params.module_solver_          = "policyiteration";
        params.solver_iteration_cnt_   = 10;            

        auto policy = MdpSolve::solve_filebased_mdp(params);

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

TEST_CASE("test solving external mdp"){

        MdpSolve::Params params;
        
        params.mdp_filepath_            = "./data/4x3.95.POMDP";
        params.module_parser_          = "cassandra";
        params.module_eval_            = "iterative";
        params.module_policy_          = "greedy";
        params.module_solver_          = "policyiteration";
        params.solver_iteration_cnt_   = 10;            

        Model newmdp;
        using PARSER_FACTORY = Factory<Parser>;
        auto parser = PARSER_FACTORY::getInstance().createInstance(params.module_parser_,newmdp);
        parser->parseFile(params.mdp_filepath_);
        auto policy = MdpSolve::solve_external_mdp(newmdp,params);

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