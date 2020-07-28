#ifndef ARRAY3D_HPP
#define ARRAY3D_HPP

#include <cstdlib>
#include <stdexcept>

//3darrays müssen nur gelesen werden und einmal aufgebaut werden!

template<typename T>
class Array3d{

    public:
        Array3d(std::size_t x_length, std::size_t y_length, std::size_t z_length): 
        xdim_(x_length),
        ydim_(y_length),
        zdim_(z_length),
        length_(x_length*y_length*z_length),
        data_(new T[x_length*y_length*z_length]){
        }

        Array3d():
        data_(nullptr){
        }

        friend void swap(Array3d& a1, Array3d& a2) {
        using std::swap;
        swap(a1.data_, a2.data_);
        }        

        //default copy constructor
        Array3d(const Array3d& a3d) = delete;
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
        Array3d& operator=(Array3d&& a3d){
            std::cout<<"move assignment"<<std::endl;
            xdim_ = a3d.xdim_;
            ydim_ = a3d.ydim_;
            zdim_ = a3d.zdim_;
            length_ = a3d.length_;
            data_ = a3d.data_;
            a3d.data_ = nullptr;
            return *this;
        }



        ~Array3d(){
            delete [] data_;
        }

        
        T& operator()(std::size_t x,std::size_t y,std::size_t z) const{
            if(x>=xdim_ || y >=ydim_ || z>=zdim_){
                throw std::out_of_range("bad index when accessing Array3d object");
            }
            else{
                return data_[z + y * ydim_ + x * ydim_ * zdim_];
            }
        }
        T& operator()(std::size_t x,std::size_t y,std::size_t z) {
            if(x>=xdim_ || y >=ydim_ || z>=zdim_){
                throw std::out_of_range("bad index when accessing Array3d object");
            }
            else{
                return data_[z + y * ydim_ + x * ydim_ * zdim_];
            }
        }        

    private:
        std::size_t xdim_;
        std::size_t ydim_;
        std::size_t zdim_;
                        
        std::size_t length_;
        T* data_;

};



#endif