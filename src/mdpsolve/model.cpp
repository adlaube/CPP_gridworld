#include "model.hpp"


void Model::SetArrays(){

    state_transition_matrix_ = Array3d<double>((std::size_t)num_of_actions_,(std::size_t)num_of_states_,(std::size_t)num_of_states_);
    reward_matrix_ = Array3d<double>((std::size_t)num_of_actions_,(std::size_t)num_of_states_,(std::size_t)num_of_states_);

}

Model::Model(const std::string filepath){


    std::ifstream inputstream;
    num_of_actions_ = 2;
    num_of_states_ = 2;
    SetArrays();

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
                while(std::getline(iss,value,' ')){ 
                    action_strings.push_back(value);
                    action_cnt++;
                }
                // ptr_actions_ = std::make_unique<std::string>(num_of_actions_);
                // action_cnt = 0;
                // char* action_chars = &action_string[0];
                // char * value_buff;
                // value_buff = std::strtok(action_chars," ");
                // while(value_buff != NULL){
                //     ptr_actions_.get()[action_cnt] = value_buff;
                //     value_buff = strtok(NULL," ");
                // }
            }         
            if (key == "T"){
                std::string value;
                std::getline(iss,value);
                num_of_states_ = std::atoi(value.c_str());   
            }
            if (key == "states"){
                std::string value;
                std::getline(iss,value);
                num_of_states_ = std::atoi(value.c_str());   
            }      
            
        }
    }
    //end of parse
}