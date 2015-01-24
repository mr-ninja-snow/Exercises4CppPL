#include <iostream>		//std::cout, std::cerr
#include "vlib.hpp"

namespace exercise = exercise_12;

int main(int argc, const char* arfgv[])
{

	static_assert(exercise::DATA_BLOCK_SIZE == 2,   "This program doesn't support a data block that isn't equal to 64 bit (block size 2)");
	static_assert(exercise::KEY_SIZE == 4,          "This program doesn't support a key that isn't equal to 128 bit (block size 4)");
	static_assert(exercise::NUMBER_OF_ROUNDS >= 64, "The TEA will be easily cracked if the number of rounds is less then 64");

	uint32_t key[exercise::KEY_SIZE] = {0};
	uint32_t data[exercise::DATA_BLOCK_SIZE] = {0};

	exercise::initKey(key);
	exercise::initData(data);

	exercise::printData(key, exercise::KEY_SIZE, "This is the key that is going to be used:");
	exercise::printData(data, exercise::DATA_BLOCK_SIZE, "This is the data that is going to be used:");

	exercise::encrypt(data, key);

	exercise::printData(data, exercise::DATA_BLOCK_SIZE, "This is the data after the encryption process:");

	exercise::decrypt(data, key);

	exercise::printData(data, exercise::DATA_BLOCK_SIZE, "This is the data after being decrypted:");

	std::cout << "\n\n\nPROFIT!!!!\n\n\n";

	return 0;
}
