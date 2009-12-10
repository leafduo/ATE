CC = g++

CXXFLAGS = -g

all:ate

ate:Formula.o Operator.o ate.o

ate.o:ate.cpp

Formula.o:Formula.cpp

Operator.o:Operator.cpp

clean:
	rm *.o ate
