CXXFLAGS = -Wall -std=c++14 -g
CXX = g++

objects = mdpsolve.o

BIN_DIR = ../bin/
LIB_DIR = ./mdpsolve/
PARSER_DIR = $(LIB_DIR)Parsers/
SOLVER_DIR = $(LIB_DIR)Solvers/
POLICY_DIR = $(LIB_DIR)Policies/
EVAL_DIR = $(LIB_DIR)Evaluations/
ENV_DIR =  $(LIB_DIR)Environments/


mdpsolve: libmdpsolve.a $(objects)
	g++ $(objects) -L$(LIB_DIR) -o $(BIN_DIR)mdpsolve -lmdpsolve -g

mdpsolve.o: $(LIB_DIR)solve.hpp $(LIB_DIR)model.hpp $(PARSER_DIR)cassandra.hpp

# call make file of subdirectory
libmdpsolve.a: 
	$(MAKE) -C $(LIB_DIR)

.PHONY: clean
clean:
	rm $(BIN_DIR)mdpsolve; rm *.o; $(MAKE) -C $(LIB_DIR) clean
	