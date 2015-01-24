#include <string>
#include <cstring>
#include <map>

#ifndef VLIB_H
#define VLIB_H

namespace exercise_10{

	//encryption
	std::string xorChractersInString(std::string text, std::string key);
	std::string encrypt(std::string plainText, std::string key);
	std::string decrypt(std::string cipherText, std::string key);

	//breaking the code
	//int findKeyLength(std::string cipherText);
	int findKeyLength(std::string cipherText, std::string cipherText2);
	//std::map<char, double> getBytePercentage(std::string text);
	bool getBytePercentage(std::string text);
	bool getBytePercentage2(std::string text);

}

#endif