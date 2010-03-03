CC = g++

#CXXFLAGS = -g -D DEBUG

all:compile

compile:ate

ate:formula.o operator.o ate.o

ate.o:ate.cpp formula.h

formula.o:formula.cpp operator.h formula.h exception.h

operator.o:operator.cpp operator.h exception.h

clean:
	rm *.o ate *~
