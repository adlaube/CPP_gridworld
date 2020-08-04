CXXFLAGS = -Wall -std=c++17 -g
CXX = g++

BIN_DIR = ../bin/
LIB_DIR = .

 #$(wildcard ./*.cpp)
cppsrc= $(wildcard mdpsolve/*.cpp)\
		$(wildcard mdpsolve/Environments/*.cpp)\
		$(wildcard mdpsolve/Evaluations/*.cpp) \
		$(wildcard mdpsolve/Policies/*.cpp) \
		$(wildcard mdpsolve/Solvers/*.cpp) \
		$(wildcard mdpsolve/Parsers/*.cpp)
obj=$(cppsrc:.cpp=.o)

#all load in order to avoid dropping the static for registration
mdpsolve: mdpsolve.o libmdpsolve.a
	$(CXX) mdpsolve.o -o $@ -L $(LIB_DIR) -o $(BIN_DIR)mdpsolve -Wl,-all_load -lmdpsolve


libmdpsolve.a: $(obj)
	ar rcs libmdpsolve.a $(obj)
	#$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY:clean
clean:
	rm -f $(obj) $(BIN_DIR)mdpsolve	libmdpsolve.a mdpsolve.o