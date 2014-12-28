#include <string>

#ifndef VLIB_H
#define VLIB_H

namespace exercise_10{

	std::string encrypt(std::string plainText, std::string key);
	std::string decrypt(std::string cipherText, std::string key);

}

#endif