#include "cassandra.hpp"
/*
bool Cassandra::readDoubleFromString(std::string in_string, double& out_double){
    char* end_ptr;
    errno = 0;
    double result = strtod(in_string.c_str(), &end_ptr);
    if (errno != 0 || *end_ptr != '\0') {
        fprintf(stderr, "the value could not be represented as a double exactly\n");
    }

}
*/

void Cassandra::parseRewardMatrix(std::istringstream* iss,Model& model) const{

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
        for (action_idx=0; action_idx<model.num_of_actions;action_idx++){
            for(next_state_idx=0;next_state_idx<model.num_of_states;next_state_idx++){
                model.reward_matrix(action_idx,start_state_idx,next_state_idx) = atof(value.c_str());
            }
        }
    }     

}

void Cassandra::parseTransitionMatrix(std::ifstream* inputstream,Model& model,const ACTION_ID action) const{

    std::string value, line;

    for (STATE_ID state_idx = 0;state_idx<model.num_of_states;state_idx++){
        std::getline(*inputstream,line); //access next line
        std::istringstream iss(line);
        STATE_ID i = 0;
        while(std::getline(iss,value,' ')){ //&& value){
            model.state_transition_matrix(action,state_idx,i) = atof(value.c_str());
            i++;
        }
        if(i != model.num_of_states){
            throw("invalid transition matrix");
        }
    }

}

//error handling
void Cassandra::parseData(std::string filepath, Model& model) const{
         
    std::string line;
    std::string value;
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
                std::getline(iss,value,' '); //skip first blank    
                std::getline(iss,value);
                auto result = std::find(model.action_strings.begin(),model.action_strings.end(),value);
                if(result == model.action_strings.end()){
                    throw("invalid action");
                }
                ACTION_ID action = result - model.action_strings.begin();
                parseTransitionMatrix(&inputstream,model,action);
            }  
            //processes one line
            if (key == "R"){

                //call
                parseRewardMatrix(&iss,model);
            }                     
        }
    }    
}

void Cassandra::parseParams(std::string filepath, Model& model) const{
    
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
                model.discount_rate = std::atof(value.c_str());
            }
            if (key == "values"){
                std::string value;
                std::getline(iss,value);
                if(value == " reward"){
                    model.optGoal = OPT_MAXIMIZE;
                }
                else if(value == " cost"){
                    model.optGoal = OPT_MINIMIZE;
                }
            }            
            if (key == "states"){
                std::string value;
                std::getline(iss,value);
                model.num_of_states = std::atoi(value.c_str()); 
            }
            if (key == "actions"){ //count whitespaces and alloc accordingly
                std::string action_string = key; //line with action
                std::string value;
                ACTION_ID action_cnt = 0;
                std::getline(iss,value,' '); //skip first blank
                while(std::getline(iss,value,' ')){ 
                    model.action_strings.push_back(value);
                    action_cnt++;
                }
                model.num_of_actions = action_cnt;
            }   
        }                     
    }                    
}