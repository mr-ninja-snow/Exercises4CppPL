#include <iostream>		//std::cout, std::cerr
#include <array>
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{
	enum { eArraySize = 500 };
	std::array<int, eArraySize> fooArray;

	exercise_7::generateArrayWithRandomNumbers(fooArray);

	float res1 = exercise_7::sort(fooArray, exercise_7::ssort);

	float res2 = exercise_7::sort(fooArray, exercise_7::newSsort);

	if (res1 > res2)
		std::cout << "\n\nThe new ssort is faster sorting a " << eArraySize << " element array by " << res1 - res2 << "\n\n";
	else
		std::cout << "\n\nThe new ssort is slower sorting a " << eArraySize << " element array by " << res2 - res1 << "\n\n";

	return 0;
}
