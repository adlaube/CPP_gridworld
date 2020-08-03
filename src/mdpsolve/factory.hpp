#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <map>
#include "model.hpp"

// using POLICY_FACTORY = Factory<Policy,Constructor<Policy>>;
// using EVALUATION_FACTORY = Factory<Evaluation,Constructor<Evaluation>>;
// using PARSER_FACTORY = Factory<Parser,Constructor<Parser>>;
// using SOLVER_FACTORY = Factory<Solver,Constructor<Solver>>;

template<typename T, typename Tconstruct>
class Factory{

    public:

        static Factory& getInstance(){
            static Factory factory;
            return factory;
        }    
        T* createInstance(const std::string name, const Model& model){

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