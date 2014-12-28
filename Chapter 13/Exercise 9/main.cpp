#include <iostream>		//std::cout, std::cerr
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{
	exercise_9::SqrMatrix matrix(3, exercise_9::WITH_RANDOM_VALUES);

	std::cout << matrix;
	const float determinant = calculateDeterminantNxNMatrix(matrix);
	std::cout << "\n\tThe determinant of the given matrix is :" << calculateDeterminantNxNMatrix(matrix) << "\n\n";

	exercise_9::SqrMatrix matrixOfMinors = calculateMatrixOfMinorsForNxNMatrix(matrix);
	std::cout << "\n\nThe matrix of minors of the given matrix is :\n" << matrixOfMinors << "\n\n";

	exercise_9::SqrMatrix cofactorMatrix = calculateCofactorMatrixFromMatrixOfMinors(matrixOfMinors);
	std::cout << "\n\nThe cofactor matrix of the given matrix is :\n" << cofactorMatrix << "\n\n";

	exercise_9::SqrMatrix transposedMatrix = getTranspositionOfMatrix(cofactorMatrix);
	std::cout << "\n\nThe transposed matrix of the given matrix is :\n" << transposedMatrix << "\n\n";

	multiplyEveryElementOfMatrixByGivenNumber(transposedMatrix, 1/determinant);
	std::cout << "\n\nThe inversed matrix of the given matrix is :\n" << transposedMatrix << "\n\n";

	exercise_9::SqrMatrix productMatrix = multiplyTwoSqrMatrices(matrix, transposedMatrix);
	std::cout << "\n\nCheck if the inveted natrix is correct:\n" << productMatrix << "\n\n";

	return 0;
}
