#ifndef MODEL_HPP
#define MODEL_HPP

#include <cassert>

#include "parser.hpp"
#include "types.hpp"


class Model{

    private:
        ModelData model_data_;
        ModelParams model_params_;

    public:
        Model(const std::string filepath, Parser parser);
        Model(const std::string filepath);
        struct ModelData* SetArrays();
        void CheckConsistency(std::string key);         
};

#endif