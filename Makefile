CXX = g++

CXXFLAGS = -Wall -std=c++11 -g


projet: projet.cpp coord.o
testcoord: testcoord.cpp coord.o


coord.o: coord.cpp coord.h

