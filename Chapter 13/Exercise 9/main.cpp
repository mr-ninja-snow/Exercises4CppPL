#include <iostream>		//std::cout, std::cerr
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{
	exercise_9::SqrMatrix matrix(3, true);

	std::cout << matrix;

	std::cout << "\n\tThe determinant of the given matrix is :" << calculateDeterminant2x2Matrix(matrix) << "\n\n";

	return 0;
}
