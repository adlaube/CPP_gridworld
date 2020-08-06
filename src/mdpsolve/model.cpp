#include "model.hpp"


void Model::SetArrays(){

    state_transition_matrix =   Array3d<double>(num_of_actions,
                                                num_of_states,
                                                num_of_states);
    reward_matrix =             Array3d<double>(num_of_actions,
                                                num_of_states,
                                                num_of_states);
}

void Model::CheckConsistency(){

    assert(0 < discount_rate && discount_rate<=1);
    assert(optGoal != OPT_UNDEFINED);
    assert(num_of_states!= 0);
    assert(num_of_actions != 0);
}

/*
hier wäre es vllt gut das File zu öffnen und dann den stream zu übergeben
und vor dem 2ten Aufruf zurückzusetzen?
Erstmal so lassen!
*/

// MODEL_SIZE Model::InitModel(const std::string filepath, const Parser& parser){
    
//     parser.parseParams(filepath,*this);
//     CheckConsistency("");
//     SetArrays();
//     parser.parseData(filepath,*this);
//     return MODEL_SIZE(this->num_of_states,this->num_of_actions);
// }

// Model::Model(const std::string filepath, const Parser& parser){

//     parser.parseParams(filepath,*this);
//     CheckConsistency("");
//     SetArrays();
//     parser.parseData(filepath,*this);
// }