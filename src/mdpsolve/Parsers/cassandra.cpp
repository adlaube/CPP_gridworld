#include "cassandra.hpp"

void Cassandra::parseData(std::string filepath, struct ModelData *model_data){
    model_data->reward_matrix(1,1,1) = 0;
}

void Cassandra::parseParams(std::string filepath, struct ModelParams *model_params){
    model_params->discount_rate = 1;
    /*
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
                    CheckConsistency(key);
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
                    CheckConsistency(key);
                }            
                if (key == "states"){
                    std::string value;
                    std::getline(iss,value);
                    num_of_states_ = std::atoi(value.c_str());
                    CheckConsistency(key); 
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
                    CheckConsistency(key);
                }         
                if (key == "T"){
                    CheckConsistency("");
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

                if (key == "R"){
                    CheckConsistency("");
                    std::string value;
                    ACTION_ID action_idx = DEF_ACTION_UNDEF;
                    STATE_ID start_state_idx = DEF_STATE_UNDEF;
                    STATE_ID next_state_idx = DEF_STATE_UNDEF;

                    std::getline(iss,value,':');

                    if (value==" * "){
                        action_idx = DEF_ACTION_ALL;
                    }
                    
                    std::getline(iss,value,':');
                    //std::getline(iss,value,' ');

                    start_state_idx = atoi(value.c_str());

                    std::getline(iss,value,':');

                    if (value==" * "){
                        next_state_idx = DEF_STATE_ALL;
                    }

                    std::getline(iss,value,'*');//skip observation, we have full observability in a MDP
                    std::getline(iss,value); 
                    if(action_idx == DEF_ACTION_ALL && next_state_idx == DEF_STATE_ALL)
                    {
                        for (action_idx=0; action_idx<num_of_actions_;action_idx++){
                            for(next_state_idx=0;next_state_idx<num_of_states_;next_state_idx++){
                                reward_matrix_(action_idx,start_state_idx,next_state_idx) = atof(value.c_str());
                            }
                        }
                    }
                    
                }                     
            }
        }    
    */
}