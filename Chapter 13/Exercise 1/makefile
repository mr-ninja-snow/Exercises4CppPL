all: exeMe

exeMe: main.o vlib.o
	g++ -o exeMe main.o vlib.o -std=c++11

main.o: main.cpp 
	g++ -c main.cpp -std=c++11

vlib.o: vlib.cpp 
	g++ -c vlib.cpp -std=c++11

clean:
	rm -rf *o exeMe