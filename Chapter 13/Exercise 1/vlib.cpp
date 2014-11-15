#include "vlib.hpp"

namespace exercise_1 {

	void foo(const char* pC, int& rI) {
		std::cout << pC << " - " << rI << "\n\n";
	}

	void foo2(const char* pC, int& rI) {
		std::cout << pC << " ::: " << rI << "\n\n";
	}

	void fooOfFoo(pFooFun2 f) {
		int i = 333;
		f("hay ", i);
	}

	pFooFun fooRetFoo( const int choice) {
		switch (choice)
		{
		case 1:
			return foo;
		default: 
			return foo2;
		};
	}

}