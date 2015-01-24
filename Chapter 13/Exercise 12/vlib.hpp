#ifndef VLIB_H
#define VLIB_H

#include <string>
#include <stdlib.h>
#include <stdint.h>
#include <random>

namespace exercise_12{

	enum
	{
		dataBlockIndex1,
		dataBlockIndex2,
		dataBlockIndex3,
		dataBlockIndex4
	};

	const size_t DATA_BLOCK_SIZE  = 2;
	const size_t KEY_SIZE         = 4;
	const size_t NUMBER_OF_ROUNDS = 64;

	// static_assert(DATA_BLOCK_SIZE != 2,  "This program doesn't support a data block that isn't equal to 64 bit (block size 2)");
	// static_assert(KEY_SIZE != 4,         "This program doesn't support a key that isn't equal to 128 bit (block size 4)");
	// static_assert(NUMBER_OF_ROUNDS < 64, "The TEA will be easily cracked if the number of rounds is less then 64");

	void encrypt(uint32_t* plainText, uint32_t* key);
	void decrypt(uint32_t* cipherText, uint32_t* key);

	uint32_t generateRandom32BitNumber();
	void initKey(uint32_t* key);
	void initData(uint32_t* data);
	void init(uint32_t* data, size_t size);

	void printData(uint32_t* data, size_t size, std::string msg);

}

#endif