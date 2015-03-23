all: exeMe

exeMe: main.o CFileIOWrapper.o
	g++ -o prog main.o CFileIOWrapper.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

CFileIOWrapper.o: CFileIOWrapper.cpp
	g++ -c CFileIOWrapper.cpp -std=c++11

clean:
	rm -rf *o prog