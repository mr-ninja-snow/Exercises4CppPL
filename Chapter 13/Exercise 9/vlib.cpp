#include <iomanip>
#include "vlib.hpp"

namespace exercise_9{

	std::ostream& operator<<(std::ostream& o, const SqrMatrix& sqrMatrix)
	{
		double const* const* matrix = sqrMatrix.getMatrix();
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

	double calculateDeterminant2x2Matrix(const SqrMatrix& sqrMatrix)
	{
		if (sqrMatrix.getNumberOfRows() != NUMBER_OF_ROWS_IN_2X2_MATRIX)
		{
			throw(IsNot2x2Matrix("This is not a 2 by 2 matrix!"));
		}

		double const* const* matrix = sqrMatrix.getMatrix();
		return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
	}

	double calculateDeterminantNxNMatrix(const SqrMatrix& sqrMatrix)
	{
		double const* const* matrix = sqrMatrix.getMatrix();
		if (sqrMatrix.getNumberOfRows() > NUMBER_OF_ROWS_IN_2X2_MATRIX)
		{
			double res = 0;
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
		SqrMatrix subMatrix(sqrMatrix.getNumberOfRows());

		int subMatrixX = 0;
		int subMatrixY = 0;

		double const* const* matrix = sqrMatrix.getMatrix();
		for (int i = 0; i < sqrMatrix.getNumberOfRows(); ++i)
		{
			if (i != row)
			{
				for (int j = 0; j < sqrMatrix.getNumberOfRows(); ++j)
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

}//namespace exercise_8
