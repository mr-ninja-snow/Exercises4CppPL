#include <iostream>		//std::cout, std::cerr
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{
	exercise_9::SqrMatrix matrix(3, exercise_9::WITH_RANDOM_VALUES);

	std::cout << matrix;

	std::cout << "\n\tThe determinant of the given matrix is :" << calculateDeterminantNxNMatrix(matrix) << "\n\n";

	exercise_9::SqrMatrix matrixOfMinors = calculateMatrixOfMinorsForNxNMatrix(matrix);

	std::cout << "\n\nThe matrix of minors of the given matrix is :\n" << matrixOfMinors << "\n\n";

	exercise_9::SqrMatrix cofactorMatrix = calculateCofactorMatrixFromMatrixOfMinors(matrixOfMinors);

	std::cout << "\n\nThe cofactor matrix of the given matrix is :\n" << cofactorMatrix << "\n\n";

	return 0;
}
