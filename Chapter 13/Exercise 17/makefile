all: exeMe

exeMe: main.o VSError.o
	g++ -o prog main.o VSError.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

VSError.o: VSError.cpp
	g++ -c VSError.cpp -std=c++11

clean:
	rm -rf *o prog