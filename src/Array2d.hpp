#ifndef ARRAY2D_HPP
#define ARRAY2D_HPP

#include <cstdlib>
#include <stdexcept>

template<typename T>
class Array2d{

    public:
        Array2d(std::size_t x_length, std::size_t y_length;
        dimensions{x_length,y_length},
        data(new T[x_length*y_length]{
        }

        //delete default constructor
        Array2d() = delete;

        //delete default copy constructor
        Array2d(const Array2d& a2d) = delete;

        //delete default assignment constructor
        Array2d& operator=(const Array2d& a2d) = delete;

        Array2d(){
            delete [] data;
        }

        
        T& operator()(std::size_t x,std::size_t y) const{
            if(x>=dimensions[0] || y >=dimensions[1]){
                throw std::out_of_range("bad index when accessing Array2d object");
            }
            else{
                return data[x*dimensions[1]+y];
            }
        }
        T& operator()(std::size_t x,std::size_t y){
            if(x>=dimensions[0] || y >=dimensions[1]){
                throw std::out_of_range("bad index when accessing Array2d object");
            }
            else{
                return data[x*dimensions[1]+y];
            }
        }        

    private:
        std::size_t dimensions[2];
        T* data;

};



#endif