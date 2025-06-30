# Makefile minimal funcional

EXEC := build/main.out

all: $(EXEC)

$(EXEC): src/main.cpp | build
	g++ -std=c++11 -O2 -Wall -o $(EXEC) src/main.cpp

build:
	mkdir -p build

run: $(EXEC)
	./$(EXEC)

clean:
	rm -rf build

