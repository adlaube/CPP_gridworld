#ifndef ARRAY3D_HPP
#define ARRAY3D_HPP

#include <stdexcept>
#include <vector>

template<typename T>
class Array3d{ 

    using DATA_VECTOR = std::vector<T>;
    private:
        std::size_t xdim_ = 0;
        std::size_t ydim_ = 0;
        std::size_t zdim_ = 0;
                        
        std::size_t length_ = 0;
        DATA_VECTOR data_;    

    public:
        
        Array3d(std::size_t x_length, std::size_t y_length, std::size_t z_length): 
            xdim_(x_length > 0 ? x_length : throw("invalid dimension")),
            ydim_(y_length > 0 ? y_length : throw("invalid dimension")),
            zdim_(z_length > 0 ? z_length : throw("invalid dimension")),
            length_(x_length*y_length*z_length),
            data_(DATA_VECTOR(x_length*y_length*z_length,0)){
        }

        Array3d() = default;
      
        const T& operator()(const std::size_t x,const std::size_t y,const std::size_t z) const{
            if((x>=(xdim_) || y >=(ydim_) || z>=(zdim_)) ||
                (length_==0)){
                throw std::out_of_range("bad index when accessing Array3d object");
            }
            else{
                return data_[z + y * ydim_ + x * ydim_ * zdim_];  //no boundary check here, faster
            }
        }
        T& operator()(std::size_t x,std::size_t y,std::size_t z) {
            if((x>=(xdim_) || y >=(ydim_) || z>=(zdim_)) ||
                (length_==0)){
                throw std::out_of_range("bad index when accessing Array3d object");
            }
            else{
                return data_[z + y * ydim_ + x * ydim_ * zdim_];  //no boundary check here, faster
            }
        }        

};



#endif