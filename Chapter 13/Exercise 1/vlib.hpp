#include <iostream>

#ifndef VLIB_H
#define VLIB_H

namespace exercise_1 {

	void foo(const char* pC, int& rI);

	void foo2(const char* pC, int& rI);

	typedef void (*pFooFun)(const char* pC, int& rI);

	using pFooFun2 = void (*)(const char* pC, int& rI);

	void fooOfFoo(pFooFun2 f);

	pFooFun fooRetFoo( const int choice);

} // exercise_1

#endif