#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <map>
#include <memory>
#include "model.hpp"
#include "constructor.hpp"
#include "module.hpp"

template<ModularType T> // ModularType concept defined in module.hpp
class Factory{

    public:
        using OBJECT_PTR = std::unique_ptr<T>;
        using CONSTRUCTOR = Constructor<T>;    
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

        void add(const std::string& name, CONSTRUCTOR* constructor){
            supportedTypes.insert(std::make_pair(name,constructor));
        }

        Factory(const Factory& factory) = delete;
        Factory& operator= (const Factory&) = delete;               

    private:
        Factory() = default;
        std::map<std::string,CONSTRUCTOR*> supportedTypes;
};

#endif