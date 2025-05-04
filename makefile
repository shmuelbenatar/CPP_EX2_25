CXX=g++
CXXFLAGS= -g -Wall -Wextra 
OBJECTS = SquareMat.cpp main.cpp
TESTOBJECTS = SquareMat.cpp TestSquareMat.cpp
all: Main test

Main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o Main
	
test: $(TESTOBJECTS)
	$(CXX) $(CXXFLAGS) $(TESTOBJECTS) -o test

valgrind: demo
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./demo

clean:
	rm -f demo test *.o