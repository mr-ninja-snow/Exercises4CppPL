all: exeMe

exeMe: main.o VSBTree.o
	g++ -o prog main.o VSBTree.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

VSBTree.o: VSBTree.cpp
	g++ -c VSBTree.cpp -std=c++11

clean:
	rm -rf *o prog