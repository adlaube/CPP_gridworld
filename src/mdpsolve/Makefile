CXXFLAGS = -Wall -std=c++14 -g 
CXX = g++

PARSER_DIR =./Parsers/
EVAL_DIR = ./Evaluations/
POLICY_DIR = ./Policies/
SOLVER_DIR = ./Solvers/

libmdpsolve.a: solve.o model.o $(PARSER_DIR)cassandra.o
	ar rcs libmdpsolve.a solve.o model.o $(PARSER_DIR)cassandra.o
solve.o:$(PARSER_DIR)cassandra.hpp model.hpp
model.o:array3d.hpp parser.hpp

$(PARSER_DIR)cassandra.o:
	$(MAKE) -C $(PARSER_DIR)

.PHONY: clean
clean:
	rm -f *.o *.a; $(MAKE) -C $(PARSER_DIR) clean