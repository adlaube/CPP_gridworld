#ifndef MODULE_HPP
#define MODULE_HPP

#include <type_traits>
#include <concepts>
#include "model.hpp"

class Module {
    protected:
        Module(Model& model):
            model_(model){

        }

    protected:
        Model& model_;

};

template <typename T>
concept ModularType  = std::is_base_of<Module,T>::value;


#endif