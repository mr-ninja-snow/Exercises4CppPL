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

	const bool WITH_RANDOM_VALUES = true;

	struct SqrMatrix
	{
		float** data;
		const int numberOfRows;

		SqrMatrix(const int size, bool randomVals = false)
		try : numberOfRows(size), data(nullptr)
		{
			std::default_random_engine e((unsigned int)time(0));
			std::uniform_int_distribution<int> distribution(0,9);

			data = new float* [numberOfRows];
			for (int i = 0; i < numberOfRows; ++i)
			{
				data[i] = new float [numberOfRows];

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

		float const* const* getMatrix() const
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

	class DiffrentSizeMatrices: public std::exception
	{
	public:
		explicit DiffrentSizeMatrices(const char* message) : msg_(message) {}
		explicit DiffrentSizeMatrices(const std::string& message) : msg_(message) {}
		virtual ~DiffrentSizeMatrices() noexcept {}

		virtual const char* what() const noexcept {
			return msg_.c_str();
		}

	protected:
		std::string msg_;
	};

	std::ostream& operator<<(std::ostream& o, const SqrMatrix& sqrMatrix);
	float calculateDeterminant2x2Matrix(const SqrMatrix&);
	float calculateDeterminantNxNMatrix(const SqrMatrix&);
	SqrMatrix calculateMatrixOfMinorsForNxNMatrix(const SqrMatrix& sqrMatrix);
	SqrMatrix calculateCofactorMatrixFromMatrixOfMinors(const SqrMatrix& matrixOfMinors);

	SqrMatrix getTranspositionOfMatrix(const SqrMatrix& matrix);

	SqrMatrix multiplyTwoSqrMatrices(const SqrMatrix& matrix1, const SqrMatrix& matrix2);
	void multiplyEveryElementOfMatrixByGivenNumber(SqrMatrix& matrix, const float number);

	const SqrMatrix getSubMatrixWithoutColAndRow(const SqrMatrix&, const int row, const int col);

}

#endif