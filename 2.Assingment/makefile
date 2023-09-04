all: compile run

compile:
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/BinarySearchTree.o -c ./src/BinarySearchTree.cpp
	
	g++ -I ./include/ -o ./bin/Main ./lib/Stack.o ./lib/BinarySearchTree.o ./src/Main.cpp
	
run:
	./bin/Main



	