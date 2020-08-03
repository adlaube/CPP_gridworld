#ifndef CONSTRUCTOR_HPP
#define CONSTRUCTOR_HPP

#include "factory.hpp"
#include "model.hpp"

template<typename T>
class Constructor{

    public:
        virtual T* create(const Model& model) const = 0;
};


#endif