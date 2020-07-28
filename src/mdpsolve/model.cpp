#include "model.hpp"


void Model::SetArrays(){

    state_transition_matrix_ = Array3d<double>((std::size_t)num_of_actions_,(std::size_t)num_of_states_,(std::size_t)num_of_states_);
    reward_matrix_ = Array3d<double>((std::size_t)num_of_actions_,(std::size_t)num_of_states_,(std::size_t)num_of_states_);

}

void Model::CheckConsistency(){

    assert(num_of_states_ != 0);
    assert(num_of_actions_ != 0);
    assert(optGoal_ != OPT_UNDEFINED);
}

Model::Model(const std::string filepath){


    std::ifstream inputstream;
    //error handling?
    inputstream.open(filepath,std::ios::in);
    
    std::string line;
    while( std::getline( inputstream, line ) )   
    {
        std::istringstream iss( line );


        std::string key;
        std::getline(iss,key,':');

        if(key[0] != '#')
        {
            if (key == "discount"){
                std::string value;
                std::getline(iss,value);
                discount_rate_ = std::atof(value.c_str());   
            }
            if (key == "values"){
                std::string value;
                std::getline(iss,value);
                if(value == " reward"){
                    optGoal_ = OPT_MAXIMIZE;
                }
                else if(value == " cost"){
                    optGoal_ = OPT_MINIMIZE;
                }
                else{
                    throw("bad value for values");
                }
            }            
            if (key == "states"){
                std::string value;
                std::getline(iss,value);
                num_of_states_ = std::atoi(value.c_str());   
            }
            if (key == "actions"){ //count whitespaces and alloc accordingly
                std::string action_string = key; //line with action
                std::string value;
                ACTION_ID action_cnt = 0;
                std::getline(iss,value,' '); //skip first blank
                while(std::getline(iss,value,' ')){ 
                    action_strings.push_back(value);
                    action_cnt++;
                }
                num_of_actions_ = action_cnt;
            }         
            if (key == "T"){
                CheckConsistency();
                SetArrays();
                std::string value;
                std::getline(iss,value,' '); //skip first blank
                                
                std::getline(iss,value);
                ACTION_ID action_idx = 0;
                
                for (auto string : action_strings){
                    if(string == value){
                        for (STATE_ID state_idx = 0;state_idx<num_of_states_;state_idx++){
                            std::getline(inputstream,line); //access next line
                            std::istringstream iss( line );
                            int i = 0;
                            while(std::getline(iss,value,' ')){
                                state_transition_matrix_(action_idx,state_idx,i) = atof(value.c_str());
                                i++;
                            }
                        }
                        
                    }
                    action_idx++;
                }
            }           
        }
    }
    //end of parse
}