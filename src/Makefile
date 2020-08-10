BIN_DIR = ../bin/
EXAMPLE_DIR = ../examples/
SRC_DIR = ./mdpsolve/
INCLUDE_DIR = ..
TEST_DIR = ../tests/

CXXFLAGS = -Wall -std=c++20 -g -I$(SRC_DIR) -I$(INCLUDE_DIR)
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

ccsrc= $(wildcard mdpsolve/*.cc)\
		$(wildcard mdpsolve/Evaluations/*.cc) \
		$(wildcard mdpsolve/Policies/*.cc) \
		$(wildcard mdpsolve/Solvers/*.cc) \
		$(wildcard mdpsolve/Parsers/*.cc)
test_obj=$(ccsrc:.cc=.o)
test_dep=$(obj:.o=.d)

#all load in order to avoid dropping the static for registration
example: $(lib) $(example_obj) $(obj) tests
ifeq ($(OS),osx)
	$(CXX) $(example_obj) -L. -o $(BIN_DIR)$@ -Wl,-all_load -lmdpsolve $(CXXFLAGS)
else
	$(CXX) $(example_obj) -L. -o $(BIN_DIR)$@ -Wl,-whole-archive -lmdpsolve -Wl,-no-whole-archive $(CXXFLAGS) 
endif

$(lib): $(obj)
	ar rcs $@ $^

-include $(dep)

%.d: %.cpp %.cc
	@$(CPP) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

tests: $(lib) $(test_obj) $(TEST_DIR)unit_tests.o
ifeq ($(OS),osx)
	$(CXX) $(test_obj) $(TEST_DIR)unit_tests.o -L. -o $(BIN_DIR)$@ -Wl,-all_load -lmdpsolve $(CXXFLAGS)
else
	$(CXX) $(test_obj) $(TEST_DIR)unit_tests.o -L. -o $(BIN_DIR)$@ -Wl,-whole-archive -lmdpsolve -Wl,-no-whole-archive $(CXXFLAGS) -I ./include
endif	

$(TEST_DIR)unit_tests.o: $(TEST_DIR)unit_tests.cpp
	g++ -o $@ -c $(TEST_DIR)unit_tests.cpp $(CXXFLAGS)	

.PHONY:clean
clean:
	rm -f $(obj) $(example_obj) $(BIN_DIR)example $(lib) $(dep) *.gcno *gcda $(test_obj) $(TEST_DIR)unit_tests.o