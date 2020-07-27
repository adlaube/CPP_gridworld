CXXFLAGS = -Wall -std=c++14 -g
CXX = g++

libmdpsolve.a: solve.o model.o
	ar rcs libmdpsolve.a solve.o model.o

solve.o: solve.hpp

model.o: array3d.hpp model.hpp

.PHONY: clean
clean:
	rm -f *.o *.a