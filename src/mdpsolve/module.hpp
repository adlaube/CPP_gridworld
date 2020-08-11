#ifndef MODULE_HPP
#define MODULE_HPP

#include "model.hpp"

class Model;

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