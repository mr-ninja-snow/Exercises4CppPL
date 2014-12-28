all: exeMe

exeMe: main.o vlib.o
	g++ -o prog main.o vlib.o -std=c++11

main.o: main.cpp 
	g++ -c main.cpp -std=c++11

vlib.o: vlib.cpp 
	g++ -c vlib.cpp -std=c++11

gdb: gmain.o gvlib.o
	g++ -go main.o vlib.o -std=c++11

gmain.o: main.cpp 
	g++ -c main.cpp -std=c++11

gvlib.o: vlib.cpp 
	g++ -c vlib.cpp -std=c++11

clean:
	rm -rf *o prog