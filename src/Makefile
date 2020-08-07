BIN_DIR = ../bin/
EXAMPLE_DIR = ../examples/
LIB_DIR = ../lib/
SRC_DIR = ./mdpsolve/

CXXFLAGS = -Wall -std=c++20 -g -I$(SRC_DIR)
CXX = g++
CC = g++

lib = libmdpsolve.a
example_src = $(EXAMPLE_DIR)gridworld.cpp
example_obj=$(example_src:.cpp=.o)

cppsrc= $(wildcard mdpsolve/*.cpp)\
		$(wildcard mdpsolve/Evaluations/*.cpp) \
		$(wildcard mdpsolve/Policies/*.cpp) \
		$(wildcard mdpsolve/Solvers/*.cpp) \
		$(wildcard mdpsolve/Parsers/*.cpp)
obj=$(cppsrc:.cpp=.o)
dep=$(obj:.o=.d)

#all load in order to avoid dropping the static for registration
example: $(lib) $(example_obj)
ifeq ($(OS),osx)
	$(CXX) $(example_obj) -L. -o $(BIN_DIR)$@ -Wl,-all_load -lmdpsolve $(CXXFLAGS)
else
	$(CXX) $(example_obj) -L. -o $(BIN_DIR)$@ -Wl,-whole-archive -lmdpsolve -Wl,-no-whole-archive $(CXXFLAGS) 
endif
	
	cp $(lib) $(LIB_DIR)

$(lib): $(obj)
	ar rcs $(lib) $(obj)

-include $(dep)

%.d: %.cpp
	@$(CPP) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@
	
	#$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY:clean
clean:
	rm -f $(obj) $(example_obj) $(BIN_DIR)example $(LIB_DIR)$(lib) $(lib) $(dep)