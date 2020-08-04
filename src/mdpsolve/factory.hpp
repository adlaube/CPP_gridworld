#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <map>
#include "model.hpp"

template<typename T, typename Tconstruct>
class Factory{

    public:

        static Factory& getInstance(){
            static Factory factory;
            return factory;
        }    
        //not a const model here because parser alters the model
        T* createInstance(const std::string name, Model& model){ 

            Tconstruct* constructorInstance = nullptr;
            auto search = supportedTypes.find(name);
            
            if (search != supportedTypes.end()) {
                std::cout << "Found " << search->first << " " << search->second << '\n';
                auto constructor = search->second ;
                constructorInstance = (Tconstruct* ) constructor;
                return constructorInstance->create(model);
            } else {
                std::cout << "Not found\n";
                return nullptr;
            }      
            
        }        

        void add(const std::string name, Tconstruct* constructor){
            supportedTypes.insert(std::make_pair(name,constructor));
        }

    private:

        std::map<std::string,Tconstruct*> supportedTypes;
};

#endif