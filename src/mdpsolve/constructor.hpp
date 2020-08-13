#ifndef CONSTRUCTOR_HPP

#define CONSTRUCTOR_HPP

#include "model.hpp"
#include "module.hpp"

template <ModularType T> // ModularType concept defined in module.hpp
class Constructor
{
      public:
	virtual T *create(Model &model) = 0;
};

#endif