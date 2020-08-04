BIN_DIR = ../bin/
EXAMPLE_DIR = ../examples/
LIB_DIR = ../lib/
SRC_DIR = ./mdpsolve/

CXXFLAGS = -Wall -std=c++17 -g -I$(SRC_DIR)
CXX = g++

lib = libmdpsolve.a
example_src = $(EXAMPLE_DIR)gridworld.cpp
example_obj=$(example_src:.cpp=.o)

cppsrc= $(wildcard mdpsolve/*.cpp)\
		$(wildcard mdpsolve/Environments/*.cpp)\
		$(wildcard mdpsolve/Evaluations/*.cpp) \
		$(wildcard mdpsolve/Policies/*.cpp) \
		$(wildcard mdpsolve/Solvers/*.cpp) \
		$(wildcard mdpsolve/Parsers/*.cpp)
obj=$(cppsrc:.cpp=.o)

#all load in order to avoid dropping the static for registration
example: $(lib) $(example_obj) 
	$(CXX) $(example_obj) -L. -o $(BIN_DIR)$@ -Wl,-all_load -lmdpsolve
	mv $(lib) $(LIB_DIR)

libmdpsolve.a: $(obj)
	ar rcs libmdpsolve.a $(obj)
	
	#$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY:clean
clean:
	rm -f $(obj) $(example_obj) $(BIN_DIR)example $(LIB_DIR)$(lib) 