#include "model.hpp"


struct ModelData* Model::SetArrays(){

    model_data_.state_transition_matrix = Array3d<double>((std::size_t)model_params_.num_of_actions,
                                                         (std::size_t)model_params_.num_of_states,
                                                         (std::size_t)model_params_.num_of_states);
    model_data_.reward_matrix = Array3d<double>((std::size_t)model_params_.num_of_actions,
                                                         (std::size_t)model_params_.num_of_states,
                                                         (std::size_t)model_params_.num_of_states);

    return &model_data_;
}

void Model::CheckConsistency(std::string key){

    bool checkAll = false;
    if(key=="") checkAll = true;
    if(key=="discount" || checkAll ==true) assert(0 < model_params_.discount_rate && model_params_.discount_rate<=1);
    if(key=="values" || checkAll == true) assert(model_params_.optGoal != OPT_UNDEFINED);
    if(key=="states" || checkAll == true) assert(model_params_.num_of_states!= 0);
    if(key=="actions" || checkAll == true) assert(model_params_.num_of_actions != 0);
}

Model::Model(const std::string filepath, Parser parser){

    //parser.parseParams(filepath,&model_params_);
    //parser.parseParams(filepath,&model_params_);

    //end of parse
}