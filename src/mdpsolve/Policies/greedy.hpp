#ifndef GREEDY_HPP
#define GREEDY_HPP

#include "../policy.hpp"
#include "../model.hpp"
#include <cstdint>


class Greedy : public Policy{
    public:
        void updatePolicy(const Model& mdp, std::vector<double>& value_function,std::vector<STATE_ID>& policy_mapping, uint16_t max_iterations) const override;
};

#endif