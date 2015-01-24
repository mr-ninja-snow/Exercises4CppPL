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

	std::string plainText = "You can try some common words and letter combinations and look for places where XORing the word with the ciphertext yields an English-looking string (which would then be the corresponding word or letter combination at the other text). Also, the ciphertext will likely have numerous 0 values corresponding to places where both messages have the same letter. Such matches are more likely to be a pair of E's or a pair of Spaces than a pair of Q's or X's.";
	std::string plainText2 = "EDIT: in the comments you're mentioning that it's indeed ASCII encoding. This makes the task much easier since many 8-bit sequences don't correspond to any legal ASCII character at all. Make a table of all the possible XORs of legal ASCII characters in your plain text and this will tell you, for each position in your text, what are the possible pairs of letters from the two messages.";
	//std::getline(std::cin, plainText);

	std::string cipherText = exercise_10::encrypt(plainText, key);
	std::cout << "\nHere is the cipher text 1 :\n" << cipherText;

	std::string cipherText2 = exercise_10::encrypt(plainText2, key);
	std::cout << "\nHere is the cipher text 1 :\n" << cipherText2;

	//std::cout << "\n\nHere is the cipher text decrypted:\n" << exercise_10::decrypt(cipherText, key) << "\n\n";


	exercise_10::findKeyLength(cipherText, cipherText2);

	// std::string cipherText3 = exercise_10::encrypt(cipherText, cipherText2);
	// std::cout << "\nHere is the cipher text 1 and XORed :\n" << cipherText3;

	// std::cout << "\n\n\n-----------------------------------------------------\n";
	// exercise_10::getBytePercentage2(cipherText3);


	return 0;
}
