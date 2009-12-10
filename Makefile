CC = g++

CXXFLAGS = -g

all:compile

compile:ate

ate:Formula.o Operator.o ate.o

ate.o:ate.cpp Formula.h Operator.h

Formula.o:Formula.cpp Operator.h

Operator.o:Operator.cpp

clean:
	rm *.o ate
