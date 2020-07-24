CXXFLAGS = -Wall -std=c++14
GCC = g++

libmdpsolve.a: solve.o model.o
	ar rcs libmdpsolve.a solve.o model.o

solve.o: solve.cpp

model.o: model.cpp array3d.hpp
.PHONY: clean
clean:
	rm -f *.o *.a