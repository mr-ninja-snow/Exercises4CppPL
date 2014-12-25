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

}//namespace exercise_8
