#include "vlib.hpp"

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

}//namespace exercise_10
