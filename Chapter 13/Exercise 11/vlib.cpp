#include "vlib.hpp"
#include <algorithm>
#include <iostream>

namespace exercise_10{

	std::string xorChractersInString(std::string text, std::string key)
	{
		if (key.size() == 0)
		{
			return text;
		}

		int keyIndex = 0;
		for (int i = 0; i < text.size(); ++i)
		{
			text[i] = text[i]^key[keyIndex++];

			if (keyIndex == key.size())
			{
				keyIndex = 0;
			}
		}

		return text;
	}

	std::string encrypt(std::string plainText, std::string key)
	{
		return xorChractersInString(plainText, key);
	}

	std::string decrypt(std::string cipherText, std::string key)
	{
		return xorChractersInString(cipherText, key);
	}


	int findKeyLength(std::string cipherText, std::string cipherText2)
	{
		// const int sizeOfCStyleCipherText = cipherText.size() + 1;
		// char cStyleCipherText[sizeOfCStyleCipherText];
		// std::strcpy(cStyleCipherText, cipherText.c_str());
		
		//std::string rotatedCipherText = cipherText2;

		std::cout << "\n\n\nCore dump was here?";
		for (int i = 1; i < /*cipherText.size()*/12; ++i)
		{
			std::rotate(cipherText2.begin(), cipherText2.begin() + i, cipherText2.end());

			std::string tmp = xorChractersInString(cipherText, cipherText2);

			if(getBytePercentage2(tmp))
				std::cout << "\n\n\n-----------------------------------------------------\n" << i;

		}
		std::cout << "\n\n\nNope";

		return 0;
	}

	bool getBytePercentage2(std::string text)
	{
		char currentChar;// = array[0];
		std::map<char, double> charPercentage;
		bool disp = false;

			for (int i = 0; i < text.size(); ++i)
			{
				currentChar = text[i];

				if (charPercentage.find(currentChar) == charPercentage.end())
				{
					size_t n = std::count(text.begin(), text.end(), currentChar);
					double percentage = (n*100)/text.size();
					//std::cout << percentage << std::endl;
					charPercentage.insert( std::pair<char, double>(currentChar, percentage));// (n/text.size())*100) );
				}
			}

			typedef std::map<char, double>::const_iterator MapIterator;
			for (MapIterator iter = charPercentage.begin(); iter != charPercentage.end(); iter++)
			{
				if (iter->second > 1)
				{
					disp = true;
					std::cout << "\t"<< iter->first << " - "<< iter->second << "\n";
				}
			}
		

		return disp;
	}

	//std::map<char, double> getBytePercentage(std::string text)
	bool getBytePercentage(std::string text)
	{
		// char currentChar;// = array[0];
		// std::map<char, double> charPercentage;
		// bool disp = false;

		// 	std::cout << "\n\t1";
		// 	//VSTEPANO for (int i = 0; i < text.size(); ++i)
		// 	{
		// 		std::cout << "\n\t\t" << i;
		// 		//currentChar = text[i];
		// 		currentChar = 'S';

		// 		if (charPercentage.find(currentChar) == charPercentage.end())
		// 		{
		// 			//VSTEPANO size_t n = std::count(text.begin(), text.end(), currentChar);
		// 			//VSTEPANO double percentage = (n*100)/text.size();
		// 			//std::cout << percentage << std::endl;
		// 			//VSTEPANO charPercentage.insert( std::pair<char, double>(currentChar, percentage));// (n/text.size())*100) );
		// 		}
		// 	}

		// 	// std::cout << "\n";
		// 	// typedef std::map<char, double>::const_iterator MapIterator;
		// 	// for (MapIterator iter = charPercentage.begin(); iter != charPercentage.end(); iter++)
		// 	// {
		// 	// 	if (iter->second > 5)
		// 	// 	{
		// 	// 		disp = true;
		// 	// 		std::cout << "\t"<< iter->first << " - "<< iter->second << "\n";
		// 	// 	}
		// 	// }
		// }
		// catch(...)
		// {
		// 	std::cout << "\n\n\nCaught that SB!";

		// }

		// return disp;
	}


}//namespace exercise_10
