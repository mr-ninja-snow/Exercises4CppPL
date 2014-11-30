#include <iostream>	//std::cout, std::cerr
#include "vlib.hpp"

int main(int argc, const char* arfgv[])
{
	enum { eArraySize = 5 };
	int fooArray[eArraySize] { 4, 3, 2, 1, 5};

	exercise_7::printIntArrayWithMsg(fooArray, eArraySize, "\nBefore sorting:\n\t");

	exercise_7::ssort(fooArray, eArraySize, sizeof(int), exercise_7::intCmp);

	exercise_7::printIntArrayWithMsg(fooArray, eArraySize, "\nAfter sorting:\n\t");

	return 0;
}
