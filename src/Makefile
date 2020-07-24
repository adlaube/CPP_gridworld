CXXFLAGS = -Wall -std=c++14
CXX = g++

objects = mdpsolve.o

BIN_DIR = ../bin/
LIB_DIR = ./mdpsolve/

mdpsolve: libmdpsolve.a $(objects)
	g++ $(objects) -L$(LIB_DIR) -o $(BIN_DIR)mdpsolve -lmdpsolve

mdpsolve.o: mdpsolve.cpp

# call make file of subdirectory
libmdpsolve.a: 
	$(MAKE) -C $(LIB_DIR)

.PHONY: clean
clean:
	rm $(BIN_DIR)mdpsolve $(objects)