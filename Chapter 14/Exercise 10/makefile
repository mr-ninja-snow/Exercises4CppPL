all: exeMe

exeMe: main.o
	g++ -o prog main.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

clean:
	rm -rf *o prog