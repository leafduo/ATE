CC = g++

#CXXFLAGS = -g -D DEBUG

all:compile

compile:ate

ate:Formula.o Operator.o ate.o

ate.o:ate.cpp Formula.h Operator.h

Formula.o:Formula.cpp Operator.h Formula.h

Operator.o:Operator.cpp Operator.h

clean:
	rm *.o ate *~
