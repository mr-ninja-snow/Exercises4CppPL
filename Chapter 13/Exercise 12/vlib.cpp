#include "vlib.hpp"
#include <iostream>

void exercise_12::encrypt(uint32_t* data, uint32_t* key)
{
	uint32_t leftDB  = data[dataBlockIndex1];
	uint32_t rightDB = data[dataBlockIndex2];

	const uint32_t delta = 0x9e3779b9;

	for (int i = 0; i < NUMBER_OF_ROUNDS; ++i)
	{
		uint32_t iDelta = (i + 1)/2 * delta;

		leftDB += (rightDB << 4 + key[dataBlockIndex1]) ^ (iDelta) ^ (rightDB >> 5 + key[dataBlockIndex2]);
		rightDB += (leftDB << 4 + key[dataBlockIndex3]) ^ (iDelta) ^ (leftDB >> 5 + key[dataBlockIndex4]);
	}

	data[dataBlockIndex2] = leftDB;
	data[dataBlockIndex1] = rightDB;
}

void exercise_12::decrypt(uint32_t* encryptedData, uint32_t* key)
{
	uint32_t leftDB  = encryptedData[dataBlockIndex1];
	uint32_t rightDB = encryptedData[dataBlockIndex2];

	const uint32_t delta = 0x9e3779b9;

	for (int i = NUMBER_OF_ROUNDS - 1; i >= 0; --i)
	{
		uint32_t iDelta = (i + 1)/2 * delta;

		leftDB -= (rightDB << 4 + key[dataBlockIndex3]) ^ (iDelta) ^ (rightDB >> 5 + key[dataBlockIndex4]);
		rightDB -= (leftDB << 4 + key[dataBlockIndex1]) ^ (iDelta) ^ (leftDB >> 5 + key[dataBlockIndex2]);
	}

	encryptedData[dataBlockIndex2] = leftDB;
	encryptedData[dataBlockIndex1] = rightDB;
}

uint32_t exercise_12::generateRandom32BitNumber()
{
	std::default_random_engine engine(std::random_device{}());
	return std::uniform_int_distribution<uint32_t>{0, UINT32_MAX}(engine);
}

void exercise_12::initKey(uint32_t* key)
{
	init(key, KEY_SIZE);
}

void exercise_12::initData(uint32_t* data)
{
	init(data, DATA_BLOCK_SIZE);
}

void exercise_12::init(uint32_t* data, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		data[i] = generateRandom32BitNumber();
	}
}

void exercise_12::printData(uint32_t* data, size_t size, std::string msg)
{
	std::cout << "\n\n" << msg;

	for (int i = 0; i < size; ++i)
	{
		std::cout << "\n\t" << data[i];
	}

	std::cout << "\n";
}
