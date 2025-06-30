# Makefile minimal funcional

all: programa

programa: main.o
	g++ -std=c++11 -O2 -Wall -o programa main.o

main.o: main.cpp
	g++ -std=c++11 -O2 -Wall -c main.cpp -o main.o

clean:
	rm -f programa main.o
