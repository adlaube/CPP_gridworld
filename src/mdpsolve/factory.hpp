#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <map>
#include <memory>
#include <concepts>
#include <type_traits>
#include "model.hpp"

template <typename T>
concept TConstructor = requires(T a){
    {a.create(Model())} -> std::convertible_to<std::unique_ptr<T>>;
};

template<typename T, typename TConstructor>
class Factory{
    using OBJECT_PTR = std::unique_ptr<T>;
    public:
        static Factory& getInstance(){
            static Factory factory;
            return factory;
        }    
        //not a const model here because parser alters the model
        OBJECT_PTR createInstance(const std::string& name, Model& model){ 

            auto iterator = supportedTypes.find(name);
            
            if (iterator != supportedTypes.end()) {
                auto constructor = iterator->second ;
                auto object_pointer = OBJECT_PTR(constructor->create(model));
                return object_pointer;
            } else {
                throw("class not registered with factory");
                return nullptr; //unreachable code
            }
            
        }        

        void add(const std::string& name, TConstructor* constructor){
            supportedTypes.insert(std::make_pair(name,constructor));
        }

        Factory(const Factory& factory) = delete;
        Factory& operator= (const Factory&) = delete;               

    private:
        Factory() = default;
        std::map<std::string,TConstructor*> supportedTypes;
};

#endif