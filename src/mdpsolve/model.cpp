#include "model.hpp"


void Model::SetArrays(){

    state_transition_matrix =   Array3d<double>(num_of_actions,
                                                num_of_states,
                                                num_of_states);
    reward_matrix =             Array3d<double>(num_of_actions,
                                                num_of_states,
                                                num_of_states);
}

void Model::CheckConsistency(const std::string key){

    bool checkAll = false;
    if(key=="") checkAll = true;
    if(key=="discount" || checkAll ==true) assert(0 < discount_rate && discount_rate<=1);
    if(key=="values" || checkAll == true) assert(optGoal != OPT_UNDEFINED);
    if(key=="states" || checkAll == true) assert(num_of_states!= 0);
    if(key=="actions" || checkAll == true) assert(num_of_actions != 0);
}

/*
hier wäre es vllt gut das File zu öffnen und dann den stream zu übergeben
und vor dem 2ten Aufruf zurückzusetzen?
Erstmal so lassen!
*/

void Model::InitModel(const std::string filepath, const Parser& parser){
    
    parser.parseParams(filepath,*this);
    CheckConsistency("");
    SetArrays();
    parser.parseData(filepath,*this);

}