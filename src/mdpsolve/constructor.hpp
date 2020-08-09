#ifndef CONSTRUCTOR_HPP

#define CONSTRUCTOR_HPP

#include <concepts>
#include <type_traits>
#include "module.hpp"
#include "model.hpp"


template <ModularType T> // ModularType concept defined in module.hpp
class Constructor{

    public:        
        virtual T* create(Model& model) = 0;
              
};

#endif