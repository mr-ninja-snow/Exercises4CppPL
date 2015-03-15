all: exeMe

exeMe: main.o VSPrint.o
	g++ -o prog main.o VSPrint.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

VSPrint.o: VSPrint.cpp
	g++ -c VSPrint.cpp -std=c++11

clean:
	rm -rf *o prog