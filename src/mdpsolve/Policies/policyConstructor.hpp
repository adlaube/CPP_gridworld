#ifndef POLICYCONSTRUCTOR_HPP
#define POLICYCONSTRUCTOR_HPP

#include "../policy.hpp"
#include "../constructor.hpp"


class PolicyConstructor : public Constructor<Policy>{

    public:
        virtual Policy* create(const Model& model) const = 0;

};
#endif

