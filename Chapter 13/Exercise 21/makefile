all: exeMe

exeMe: main.o VSDate.o
	g++ -o prog main.o VSDate.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

VSDate.o: VSDate.cpp
	g++ -c VSDate.cpp -std=c++11

clean:
	rm -rf *o prog