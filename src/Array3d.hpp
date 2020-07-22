#ifndef ARRAY3D_HPP
#define ARRAY3D_HPP

#include <cstdlib>
#include <stdexcept>

//3darrays müssen nur gelesen werden und einmal aufgebaut werden!

template<typename T>
class Array3d{

    public:
        Array3d(std::size_t x_length, std::size_t y_length, std::size_t z_length): 
        dimensions{x_length,y_length,z_length},
        data(new T[x_length*y_length*z_length]){
        }

        //delete default constructor
        Array3d() = delete;

        //delete default copy constructor
        Array3d(const Array3d& a3d) = delete;

        //delete default assignment constructor
        Array3d& operator=(const Array3d& a3d) = delete;

        ~Array3d(){
            delete [] data;
        }

        
        T& operator()(std::size_t x,std::size_t y,std::size_t z) const{
            if(x>=dimensions[0] || y >=dimensions[1] || z>=dimensions[2]){
                throw std::out_of_range("bad index when accessing Array3d object");
            }
            else{
                return data[z + y * dimensions[1] + x * dimensions[1] * dimensions[2]];
            }
        }
        T& operator()(std::size_t x,std::size_t y,std::size_t z) {
            if(x>=dimensions[0] || y >=dimensions[1] || z>=dimensions[2]){
                throw std::out_of_range("bad index when accessing Array3d object");
            }
            else{
                return data[z + y * dimensions[1] + x * dimensions[1] * dimensions[2]];
            }
        }        

    private:
        std::size_t dimensions[3];
        T* data;

};



#endif