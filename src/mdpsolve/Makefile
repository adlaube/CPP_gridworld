CXXFLAGS = -Wall -std=c++14 -g 
CXX = g++

PARSER_DIR =./Parsers/

libmdpsolve.a: solve.o model.o $(PARSER_DIR)cassandra.o
	ar rcs libmdpsolve.a solve.o model.o $(PARSER_DIR)cassandra.o
solve.o:$(PARSER_DIR)cassandra.hpp types.hpp model.hpp
model.o:array3d.hpp parser.hpp types.hpp

$(PARSER_DIR)cassandra.o:
	$(MAKE) -C $(PARSER_DIR)

.PHONY: clean
clean:
	rm -f *.o *.a; $(MAKE) -C $(PARSER_DIR) clean