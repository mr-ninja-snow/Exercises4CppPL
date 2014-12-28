#include <iostream>		//std::cout, std::cerr
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{
	exercise_9::SqrMatrix matrix(3, exercise_9::WITH_RANDOM_VALUES);
	// exercise_9::SqrMatrix matrix(3);
	// matrix.data[0][0] = 1;
	// matrix.data[1][0] = 1;
	// matrix.data[2][0] = 1;
	// matrix.data[0][1] = 3;
	// matrix.data[1][1] = 4;
	// matrix.data[2][1] = 3;
	// matrix.data[0][2] = 3;
	// matrix.data[1][2] = 3;
	// matrix.data[2][2] = 4;
	std::cout << matrix;
	const double determinant = calculateDeterminantNxNMatrix(matrix);
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
