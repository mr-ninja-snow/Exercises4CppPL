#include <iostream>		//std::cout, std::cerr
#include <array>
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{
	enum { eArraySize = 5 };
	std::array<int, eArraySize> fooArray { 4, 3, 2, 1, 5};

	float res1 = exercise_7::sort(fooArray, exercise_7::ssort);

	/*vTimer::Timer t;




	std::cout <<  "\nBefore sorting:\n\t" << fooArray;

	t.startTimer();
	exercise_7::ssort(fooArray.data(), fooArray.size(), sizeof(int), exercise_7::intCmp);
	t.stopTimer();

	std::cout <<  "\nAfter sorting:\n\t" << fooArray;
	std::cout << "duration: " << t.getResult() << "s" << std::endl;

	float res1 = t.getResult();



	fooArray = { 4, 3, 2, 1, 5};





	std::cout <<  "\nBefore sorting:\n\t" << fooArray;

	t.startTimer();
	exercise_7::newSsort(fooArray.data(), eArraySize, sizeof(int), exercise_7::intCmp);
	t.stopTimer();

	std::cout <<  "\nAfter sorting:\n\t" << fooArray;
	std::cout << "duration: " << t.getResult() << "s" << std::endl;




	if (res1 > t.getResult())
		std::cout << "\n\nThe new ssort is faster\n\n";
	else
		std::cout << "\n\nThe new ssort is slower\n\n";
*/
	return 0;
}
