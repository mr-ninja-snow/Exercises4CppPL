#include <cstring>
#include <vector>
#include <algorithm>    // std::copy
#include <random>
#include <iostream>		//std::cout, std::cerr

#ifndef VLIB_H
#define VLIB_H

namespace exercise_9{

	const unsigned char PADDING_SIZE = 3;
	const unsigned char NUMBER_OF_ROWS_IN_2X2_MATRIX = 2;

	struct SqrMatrix
	{
		double** data;
		const int numberOfRows;

		SqrMatrix(const int size, bool randomVals = false)
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
					if (randomVals)
						data[i][j] = distribution(e);
					else
						data[i][j] = 0;
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

				std::cerr << "Couldn't create an instance of SqrMatrix!" << std::endl;
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

	class IsNot2x2Matrix: public std::exception
	{
	public:
		explicit IsNot2x2Matrix(const char* message) : msg_(message) {}
		explicit IsNot2x2Matrix(const std::string& message) : msg_(message) {}
		virtual ~IsNot2x2Matrix() noexcept {}

		virtual const char* what() const noexcept {
			return msg_.c_str();
		}

	protected:
		std::string msg_;
	};

	std::ostream& operator<<(std::ostream& o, const SqrMatrix& sqrMatrix);
	double calculateDeterminant2x2Matrix(const SqrMatrix&);
	double calculateDeterminantNxNMatrix(const SqrMatrix&);

	const SqrMatrix getSubMatrixWithoutColAndRow(const SqrMatrix&, const int row, const int col);

}

#endif