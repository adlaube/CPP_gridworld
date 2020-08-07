#ifndef ARRAY3D_HPP
#define ARRAY3D_HPP

#include <cstdlib>
#include <stdexcept>
#include <vector>

//3darrays müssen nur gelesen werden und einmal aufgebaut werden!

template<typename T>
class Array3d{

    public:
        using DATA_VECTOR = std::vector<T>;
        Array3d(std::size_t x_length, std::size_t y_length, std::size_t z_length): 
            xdim_(x_length),
            ydim_(y_length),
            zdim_(z_length),
            length_(x_length*y_length*z_length),
            data_(DATA_VECTOR(x_length*y_length*z_length,0)){
        }

        Array3d() = default;

        // friend void swap(Array3d& a1, Array3d& a2) {
        //     using std::swap;
        //     swap(a1.data_, a2.data_);
        // }        

        //default copy constructor
        // Array3d(const Array3d& a3d) = delete;
        // xdim_(a3d.xdim_),
        // ydim_(a3d.ydim_),
        // zdim_(a3d.zdim_),
        // length_(a3d.length_),
        // data_(a3d.data_? new T[length_] : nullptr){
        //     if(data_){
        //         std::copy(a3d.data_,a3d.data_ + a3d.length_,data_);
        //     }            
        // }

        //define move assignment operator
        // Array3d& operator=(Array3d&& a3d){
        //     xdim_ = a3d.xdim_;
        //     ydim_ = a3d.ydim_;
        //     zdim_ = a3d.zdim_;
        //     length_ = a3d.length_;
        //     data_ = a3d.data_;  //vector copy operation
        //     return *this;
        // }
        
        const T& operator()(const std::size_t x,const std::size_t y,const std::size_t z) const{
            if(x>=xdim_ || y >=ydim_ || z>=zdim_){
                throw std::out_of_range("bad index when accessing Array3d object");
            }
            else{
                return data_[z + y * ydim_ + x * ydim_ * zdim_];  //no boundary check here, faster
            }
        }
        T& operator()(std::size_t x,std::size_t y,std::size_t z) {
            if(x>=xdim_ || y >=ydim_ || z>=zdim_){
                throw std::out_of_range("bad index when accessing Array3d object");
            }
            else{
                return data_[z + y * ydim_ + x * ydim_ * zdim_];  //no boundary check here, faster
            }
        }        

    private:
        std::size_t xdim_ = 0;
        std::size_t ydim_ = 0;
        std::size_t zdim_ = 0;
                        
        std::size_t length_ = 0;
        DATA_VECTOR data_;

};



#endif