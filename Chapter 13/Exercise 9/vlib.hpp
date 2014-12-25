#include <cstring>
#include <vector>
#include <algorithm>    // std::copy
#include <random>
#include <iostream>		//std::cout, std::cerr

#ifndef VLIB_H
#define VLIB_H

namespace exercise_9{

	const int PADDING_SIZE = 3;

	struct SqrMatrix
	{
		double** data;
		const int numberOfRows;

		SqrMatrix(const int size)
		try : numberOfRows(size), data(nullptr)
		{
			std::default_random_engine e((unsigned int)time(0));
			std::uniform_int_distribution<int> distribution(0,99);

			data = new double* [numberOfRows];
			for (int i = 0; i < numberOfRows; ++i)
			{
				data[i] = new double [numberOfRows];

				for (int j = 0; j < numberOfRows; ++j)
				{
					data[i][j] = distribution(e);
				}
			}
		}
		catch(...)
		{
			if (data)
			{
				for (int i = 0; i < numberOfRows; ++i)
					if (data[i])
						delete [] data[i];

				delete [] data;

				std::cerr << "Coudn't create an instgance of SqrMatrix!" << std::endl;
				throw;
			}
		}

		~SqrMatrix()
		{
			for (int i = 0; i < numberOfRows; ++i)
				delete [] data[i];

			delete [] data;
		}

		int getNumberOfRows() const
		{
			return numberOfRows;
		}

		double const* const* getMatrix() const
		{
			return data;
		}

	};

	std::ostream& operator<<(std::ostream& o, const SqrMatrix& sqrMatrix);

}

#endif