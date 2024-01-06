all: compile run

compile:
	g++ -I ./include/ -o ./lib/Node.o ./src/Node.cpp -c
	g++ -I ./include/ -o ./lib/Iterator.o ./src/Iterator.cpp -c
	g++ -I ./include/ -o ./lib/AVL.o ./src/AVL.cpp -c 
	g++ -I ./include/ -o ./lib/LinkedList.o ./src/LinkedList.cpp -c 
	g++ -I ./include/ -o ./lib/Stack.o ./src/Stack.cpp -c
	g++ -I ./include/ -o ./bin/Test ./lib/AVL.o ./lib/Stack.o ./lib/Iterator.o ./lib/Node.o ./lib/LinkedList.o ./src/Test.cpp
	
run:
	cls
	./bin/Test