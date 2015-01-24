#include <iostream>		//std::cout, std::cerr
#include "vlib.hpp"

namespace exercise = exercise_12;

int main(int argc, const char* arfgv[])
{

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
