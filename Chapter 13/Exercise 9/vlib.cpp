#include <iomanip>
#include "vlib.hpp"

namespace exercise_9{

	std::ostream& operator<<(std::ostream& o, const SqrMatrix& sqrMatrix)
	{
		float const* const* matrix = sqrMatrix.getMatrix();
		for (int i = 0; i < sqrMatrix.getNumberOfRows(); ++i)
		{
			for (int j = 0; j < sqrMatrix.getNumberOfRows(); ++j)
			{
				o << std::setw(PADDING_SIZE) << matrix[i][j] << " ";
			}
			o << "\n";
		}

		return o;
	}

	float calculateDeterminant2x2Matrix(const SqrMatrix& sqrMatrix)
	{
		if (sqrMatrix.getNumberOfRows() != NUMBER_OF_ROWS_IN_2X2_MATRIX)
		{
			throw(IsNot2x2Matrix("This is not a 2 by 2 matrix!"));
		}

		float const* const* matrix = sqrMatrix.getMatrix();
		return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
	}

	float calculateDeterminantNxNMatrix(const SqrMatrix& sqrMatrix)
	{
		float const* const* matrix = sqrMatrix.getMatrix();
		if (sqrMatrix.getNumberOfRows() > NUMBER_OF_ROWS_IN_2X2_MATRIX)
		{
			float res = 0;
			int sign = 1;
			for (int i = 0; i < sqrMatrix.getNumberOfRows(); ++i)
			{
				res += sign * (matrix[0][i]) * calculateDeterminantNxNMatrix( getSubMatrixWithoutColAndRow(sqrMatrix, 0, i));
				sign *= (-1);
			}
			return res;
		}
		else
		{
			return calculateDeterminant2x2Matrix(sqrMatrix);
		}
	}

	const SqrMatrix getSubMatrixWithoutColAndRow(const SqrMatrix& sqrMatrix, const int row, const int col)
	{
		const int numberOfRows = sqrMatrix.getNumberOfRows();
		SqrMatrix subMatrix(numberOfRows - 1);

		int subMatrixX = 0;
		int subMatrixY = 0;

		float const* const* matrix = sqrMatrix.getMatrix();
		for (int i = 0; i < numberOfRows; ++i)
		{
			if (i != row)
			{
				for (int j = 0; j < numberOfRows; ++j)
				{
					if (j != col)
					{
						//vstepano bad design: accessing "private" data
						subMatrix.data[subMatrixY][subMatrixX] = matrix[i][j];
						subMatrixX++;
					}
				}
				subMatrixX = 0;
				subMatrixY++;
			}
		}

		return subMatrix;
	}

	SqrMatrix calculateMatrixOfMinorsForNxNMatrix(const SqrMatrix& sqrMatrix)
	{
		const int numberOfRows = sqrMatrix.getNumberOfRows();
		SqrMatrix matrixOfMinors(numberOfRows);

		for (int i = 0; i < numberOfRows; ++i)
		{
			for (int j = 0; j < numberOfRows; ++j)
			{
				matrixOfMinors.data[i][j] = calculateDeterminantNxNMatrix( getSubMatrixWithoutColAndRow(sqrMatrix, i, j));
			}
		}

		return matrixOfMinors;
	}

	SqrMatrix calculateCofactorMatrixFromMatrixOfMinors(const SqrMatrix& matrixOfMinors)
	{
		const int numberOfRows = matrixOfMinors.getNumberOfRows();
		SqrMatrix cofactorMatrix(numberOfRows);

		int sign = 1;
		for (int i = 0; i < numberOfRows; ++i)
		{
			if ((i % 2) == 0)
				sign = 1;
			else
				sign = -1;

			for (int j = 0; j < numberOfRows; ++j)
			{
				cofactorMatrix.data[i][j] = (sign * matrixOfMinors.data[i][j]);
				sign *= (-1);
			}
		}

		return cofactorMatrix;
	}

	SqrMatrix getTranspositionOfMatrix(const SqrMatrix& matrix)
	{
		const int numberOfRows = matrix.getNumberOfRows();
		SqrMatrix transpostedMatrix(numberOfRows);

		for (int i = 0; i < numberOfRows; ++i)
		{
			for (int j = 0; j < numberOfRows; ++j)
			{
				transpostedMatrix.data[i][j] = matrix.data[j][i];
			}
		}

		return transpostedMatrix;
	}

	void multiplyEveryElementOfMatrixByGivenNumber(SqrMatrix& matrix, const float number)
	{
		const int numberOfRows = matrix.getNumberOfRows();

		for (int i = 0; i < numberOfRows; ++i)
		{
			for (int j = 0; j < numberOfRows; ++j)
			{
				matrix.data[j][i] *= number;
			}
		}
	}

	SqrMatrix multiplyTwoSqrMatrices(const SqrMatrix& matrix1, const SqrMatrix& matrix2)
	{
		if (matrix1.getNumberOfRows() != matrix2.getNumberOfRows())
		{
			throw(DiffrentSizeMatrices("The two given matrices can't be multiplied, because the number of rows of the 1st matrix doesn't match the number of columns of the 2nd matrix!"));
		}

		const int numberOfRows = matrix1.getNumberOfRows();
		SqrMatrix productMatrix(numberOfRows);

		for (int i = 0; i < numberOfRows; ++i)
		{
			for (int j = 0; j < numberOfRows; ++j)
			{
				productMatrix.data[i][j] = 0;
				for (int k = 0; k < numberOfRows; ++k)
				{
					productMatrix.data[i][j] += matrix1.data[i][k]*matrix2.data[k][j];
				}
			}
		}

		return productMatrix;
	}

}//namespace exercise_9
