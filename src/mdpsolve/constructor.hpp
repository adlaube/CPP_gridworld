#ifndef CONSTRUCTOR_HPP

#define CONSTRUCTOR_HPP

#include <concepts>
#include <type_traits>
#include "factory.hpp"
#include "module.hpp"
#include "model.hpp"

//enfore constructor to comply with modular interface
template <typename T>
concept ModularType = requires(T a){
    {a(Model())} -> std::convertible_to<Module>;
};

template<typename ModularType>
class Constructor{

    public:        
        virtual ModularType* create(Model& model) = 0;
              
};

#endif