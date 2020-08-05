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

            auto iterator = supportedTypes.find(name);
            
            if (iterator != supportedTypes.end()) {
                std::cout << "Found " << iterator->first << " " << iterator->second << '\n';
                auto constructor = iterator->second ;
                return constructor->create(model);
            } else {
                std::cout << "Not found\n";
                return nullptr;
            }      
            
        }        

        void add(const std::string name, Tconstruct* constructor){
            supportedTypes.insert(std::make_pair(name,constructor));
        }

        Factory(const Factory& factory) = delete;
        Factory& operator= (const Factory&) = delete;               

    private:
        Factory() = default;
        std::map<std::string,Tconstruct*> supportedTypes;
};

#endif