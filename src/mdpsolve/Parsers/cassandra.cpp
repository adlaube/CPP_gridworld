#include "cassandra.hpp"

void parseRewardMatrix(std::istringstream* iss,struct ModelData *model_data,struct ModelParams *model_params){

    std::string value;
    ACTION_ID action_idx = DEF_ACTION_UNDEF;
    STATE_ID start_state_idx = DEF_STATE_UNDEF;
    STATE_ID next_state_idx = DEF_STATE_UNDEF;
    std::getline(*iss,value,':');
    if (value==" * "){
        action_idx = DEF_ACTION_ALL;
    }
    
    std::getline(*iss,value,':');
    start_state_idx = atoi(value.c_str());
    std::getline(*iss,value,':');
    if (value==" * "){
        next_state_idx = DEF_STATE_ALL;
    }

    std::getline(*iss,value,'*');//skip observation, we have full observability in a MDP
    std::getline(*iss,value); 
    if(action_idx == DEF_ACTION_ALL && next_state_idx == DEF_STATE_ALL)
    {
        for (action_idx=0; action_idx<model_params->num_of_actions;action_idx++){
            for(next_state_idx=0;next_state_idx<model_params->num_of_states;next_state_idx++){
                model_data->reward_matrix(action_idx,start_state_idx,next_state_idx) = atof(value.c_str());
            }
        }
    }     

}

void parseTransitionMatrix(std::ifstream* inputstream,struct ModelData *model_data,struct ModelParams *model_params){

    std::string value;
    std::getline(*inputstream,value,' '); //skip first blank    
    std::getline(*inputstream,value);
    ACTION_ID action_idx = 0;

    for (auto string : model_params->action_strings){
        if(string == value){
            for (STATE_ID state_idx = 0;state_idx<model_params->num_of_states;state_idx++){
                std::getline(*inputstream,value); //access next line
                STATE_ID i = 0;
                while(std::getline(*inputstream,value,' ')){
                    model_data->state_transition_matrix(action_idx,state_idx,i) = atof(value.c_str());
                    i++;
                }
            }
            
        }
        action_idx++;
    } 
}

//error handling
void Cassandra::parseData(std::string filepath, struct ModelData *model_data,struct ModelParams *model_params){
         
    std::string line;
    std::ifstream inputstream;
    inputstream.open(filepath,std::ios::in);
    
    while( std::getline( inputstream, line ) ){
        std::istringstream iss( line );


        std::string key;
        std::getline(iss,key,':');

        if(key[0] != '#')
        {         
            //processes multiple lines
            if (key == "T"){
                parseTransitionMatrix(&inputstream,model_data,model_params);
            }  
            //processes one line
            if (key == "R"){

                //call
            }                     
        }
    }    
}

void Cassandra::parseParams(std::string filepath, struct ModelParams *model_params){
    
    std::ifstream inputstream;
    inputstream.open(filepath,std::ios::in);
    std::string line;
    while( std::getline( inputstream, line ) ){
        std::istringstream iss( line );
        std::string key;
        std::getline(iss,key,':');
        if(key[0] != '#'){
            if (key == "discount"){
                std::string value;
                std::getline(iss,value);
                model_params->discount_rate = std::atof(value.c_str());
            }
            if (key == "values"){
                std::string value;
                std::getline(iss,value);
                if(value == " reward"){
                    model_params->optGoal = OPT_MAXIMIZE;
                }
                else if(value == " cost"){
                    model_params->optGoal = OPT_MINIMIZE;
                }
            }            
            if (key == "states"){
                std::string value;
                std::getline(iss,value);
                model_params->num_of_states = std::atoi(value.c_str()); 
            }
            if (key == "actions"){ //count whitespaces and alloc accordingly
                std::string action_string = key; //line with action
                std::string value;
                ACTION_ID action_cnt = 0;
                std::getline(iss,value,' '); //skip first blank
                while(std::getline(iss,value,' ')){ 
                    model_params->action_strings.push_back(value);
                    action_cnt++;
                }
                model_params->num_of_actions = action_cnt;
            }   
        }                     
    }                    
}