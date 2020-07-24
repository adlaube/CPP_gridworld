#include "model.hpp"


Model::Model(const std::string filepath){

    std::ifstream inputstream;

    //error handling?
    inputstream.open(filepath,std::ios::in);
    
    std::string line;
    while( std::getline( inputstream, line ) )   
    {
        std::istringstream iss( line );


        std::string result;
        std::getline(iss,result);

        if(result[0] != '#')
        {
            if( std::getline(iss,result, ':')){ // delimiter :
                if (result == "discount: "){
                    std::string value;
                    std::getline(iss,value);
                    std::cout<<value;    
                }

            }  
        }
    }
}