#ifndef MODEL_HPP
#define MODEL_HPP

#include <cstdint>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

#include "array3d.hpp"
//#include "parser.hpp"

typedef uint16_t STATE_ID;
typedef uint16_t ACTION_ID;

/*

maybe we make an MDP as singleton?
Than state::vector would make sense so it can grow shrink for the next mdp?
Start belief can be ignored because value because policy is optimal for every starting state
reward structure: action : start_state : end_state
R: <action> : <start-state> : <end-state> : <observation> %f
*/

//matrix name(sizeX, std::vector<double>(sizeY));

class Model{

    private:
        
        void SetArrays();        //std::unique_ptr<Array3d<double>> state_transition_matrix_;
        void AddTransition(); //eine action hinzufügen
        //Alternative    std::tuple<size_t, double> sampleSR(size_t s,size_t a) const;   // From a state-action pair, return a new state-reward pair
        Array3d<double> state_transition_matrix_;
        Array3d<double> reward_matrix_; //flat matrix instead of 3d (action,start_state,next_state)

        STATE_ID num_of_states_;
        ACTION_ID num_of_actions_;

        std::vector<std::string> action_strings;

        float discount_rate_;

        enum optimizationGoal{
            OPT_MAXIMIZE,
            OPT_MINIMIZE
        } optGoal_;

    public:

        
        Model(const std::string filepath);
        STATE_ID get_num_of_states(){
            return num_of_states_;
        }

        //would require copy constructor
        // Array3d<double> get_state_transition_matrix(){
        //     return state_transition_matrix;
        // }      
        
        // Array3d<double> get_reward_structure(){
        //     return reward_structure;
        // }            

        float get_discount_rate()
        {
            return discount_rate_;
        }        
};

#endif