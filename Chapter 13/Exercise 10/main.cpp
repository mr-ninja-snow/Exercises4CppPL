#include <iostream>		//std::cout, std::cerr
#include <string>
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{

	std::string key;
	if (arfgv[1])
	{
		key = arfgv[1];
	}
	else
	{
		key = "";
	}

	std::cout << "\nkey - " << key;

	std::cout << "\nEnter text:\n";

	std::string plainText;
	std::getline(std::cin, plainText);

	std::string cipherText = exercise_10::encrypt(plainText, key);
	std::cout << "\nHere is the cipher text:\n" << cipherText;

	std::cout << "\n\nHere is the cipher text decrypted:\n" << exercise_10::decrypt(cipherText, key) << "\n\n";

	return 0;
}
