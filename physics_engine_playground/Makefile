CXXFLAGS = -std=c++11 -g -Wall

all: object.o system.o main.o
	g++ object.o main.o $(CXXFLAGS) -o a.out

object.o: object.cpp object.h common.h
	g++ $(CXXFLAGS) -c object.cpp

system.o: system.cpp system.h
	g++ $(CXXFLAGS) -c system.cpp

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp
