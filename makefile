exeMe: main.o mylib.o
	g++ -o hw main.o mylib.o -std=c++11

main.o: main.cpp 
	g++ -c main.cpp -std=c++11

mylib.o: mylib.cpp 
	g++ -c mylib.cpp -std=c++11
