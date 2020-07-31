CXXFLAGS = -Wall -std=c++14 -g
CXX = g++

BIN_DIR = ../bin/
LIB_DIR = ./mdpsolve/

cppsrc=$(wildcard ./*.cpp)\
		$(wildcard mdpsolve/*.cpp)\
		$(wildcard mdpsolve/Environments/*.cpp)\
		$(wildcard mdpsolve/Evaluations/*.cpp) \
		$(wildcard mdpsolve/Policies/*.cpp) \
		$(wildcard mdpsolve/Solvers/*.cpp) \
		$(wildcard mdpsolve/Parsers/*.cpp)
obj=$(cppsrc:.cpp=.o)

mdpsolve: libmdpsolve.a $(obj)
	g++ $(obj) -L$(LIB_DIR) -o $(BIN_DIR)mdpsolve -lmdpsolve -g


libmdpsolve.a: $(obj)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY:clean
clean:
	rm -f $(obj) $(BIN_DIR)mdpsolve	libmdpsolve.a