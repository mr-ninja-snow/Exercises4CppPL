#include <iostream>		//std::cout, std::cerr
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{
	exercise_9::SqrMatrix matrix(3, exercise_9::WITH_RANDOM_VALUES);

	std::cout << matrix;

	std::cout << "\n\tThe determinant of the given matrix is :" << calculateDeterminantNxNMatrix(matrix) << "\n\n";

	return 0;
}
