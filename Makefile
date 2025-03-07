CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test stack-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

# llrec tester
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp -o llrec.o

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp -o llrec-test.o

llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) llrec-test.o llrec.o -o llrec-test

# stack tester
stack_test.o: stack-test.cpp stack.h
	$(CXX) $(CXXFLAGS) -c stack-test.cpp -o stack-test.o

stack_test: stack_test.o
	$(CXX) $(CXXFLAGS) stack-test.o -o stack-test


clean:
	rm -f *.o rh llrec-test stack-test *~
	
.PHONY: clean 