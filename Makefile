BIN_DIR = ./bin/
EXAMPLE_DIR = ./examples/
SRC_DIR = ./src/mdpsolve/
INCLUDE_DIR = .
TEST_DIR = ./tests/

CXXFLAGS = -Wall -std=c++20 -g -I$(SRC_DIR) -I$(INCLUDE_DIR) -MMD
CXX = g++
CC = g++

lib = libmdpsolve.a
example_src = $(EXAMPLE_DIR)gridworld.cpp
example_obj=$(example_src:.cpp=.o)

cppsrc= $(wildcard src/mdpsolve/*.cpp)\
		$(wildcard src/mdpsolve/Evaluations/*.cpp) \
		$(wildcard src/mdpsolve/Policies/*.cpp) \
		$(wildcard src/mdpsolve/Solvers/*.cpp) \
		$(wildcard src/mdpsolve/Parsers/*.cpp)
obj=$(cppsrc:.cpp=.o)
dep=$(obj:.o=.d)

ccsrc= $(wildcard src/mdpsolve/*.cc)\
		$(wildcard src/mdpsolve/Evaluations/*.cc) \
		$(wildcard src/mdpsolve/Policies/*.cc) \
		$(wildcard src/mdpsolve/Solvers/*.cc) \
		$(wildcard src/mdpsolve/Parsers/*.cc)
test_obj=$(ccsrc:.cc=.o)
test_dep=$(test_obj:.o=.d)

#all load in order to avoid dropping the static for registration
example: $(lib) $(example_obj) $(obj) tests
ifeq ($(OS),osx)
	$(CXX) $(example_obj) -L. -o $(BIN_DIR)$@ -Wl,-all_load -lmdpsolve $(CXXFLAGS)
else
	$(CXX) $(example_obj) -L. -o $(BIN_DIR)$@ -Wl,-whole-archive -lmdpsolve -Wl,-no-whole-archive $(CXXFLAGS) 
endif

$(lib): $(obj)
	ar rcs $@ $^

# %.d: %.cpp %.cc
# 	@$(CPP) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

tests: $(lib) $(test_obj) $(TEST_DIR)unit_tests.o
ifeq ($(OS),osx)
	$(CXX) $(test_obj) $(TEST_DIR)unit_tests.o -L. -o $(BIN_DIR)$@ -Wl,-all_load -lmdpsolve $(CXXFLAGS)
else
	$(CXX) $(test_obj) $(TEST_DIR)unit_tests.o -L. -o $(BIN_DIR)$@ -Wl,-whole-archive -lmdpsolve -Wl,-no-whole-archive $(CXXFLAGS) -I ./include
endif

-include $(dep)
-include $(test_dep)

$(TEST_DIR)unit_tests.o: $(TEST_DIR)unit_tests.cpp
	g++ -o $@ -c $(TEST_DIR)unit_tests.cpp $(CXXFLAGS)	

.PHONY:clean
clean:
	rm -f $(obj) $(example_obj) $(BIN_DIR)example $(BIN_DIR)tests $(lib) $(test_obj) $(TEST_DIR)unit_tests.o $(test_dep) $(dep)
