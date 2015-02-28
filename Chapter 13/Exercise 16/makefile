all: exeMe

exeMe: main.o MacroProcessor.o
	g++ -o prog main.o MacroProcessor.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

MacroProcessor.o: MacroProcessor.cpp 
	g++ -c MacroProcessor.cpp -std=c++11

clean:
	rm -rf *o prog