#ifndef MODEL_HPP
#define MODEL_HPP

#include <cassert>

#include "parser.hpp"
#include "types.hpp"


class Model{

    private:
        ModelData model_data_;
        ModelParams model_params_;
        void SetArrays();
        void CheckConsistency(std::string key);         

    public:
        Model(const std::string filepath, Parser parser);
        
};

#endif