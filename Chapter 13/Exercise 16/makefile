all: exeMe

exeMe: main.o Error.o Lexer.o Parser.o
	g++ -o prog main.o Error.o Lexer.o Parser.o -std=c++11

Error.o: Error.cpp 
	g++ -c Error.cpp -std=c++11

Lexer.o: Lexer.cpp 
	g++ -c Lexer.cpp -std=c++11

Parser.o: Parser.cpp 
	g++ -c Parser.cpp -std=c++11

clean:
	rm -rf *o prog