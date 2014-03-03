#include <iostream>
#include <string>
#include <vector>

std::string CmdLineInputToString(int argc, const char* arfgv[])
{
	std::string cmdLineInput;

	for (int i = 1; i < argc; i++)
	{
		if (i!=1)
			cmdLineInput += " ";
		cmdLineInput += arfgv[i];
	}

	return cmdLineInput;
}

short QuestCount1(std::string str)
{
	short questCount = 0;

	for (int i = 0; i < str.size(); ++i)
	{
		if(str[i] == '?')
			questCount++;
	}

	return questCount;
}

short QuestCount2(std::string str)
{
	short questCount = 0;
	const char* p = str.c_str();
	int i = 0;

	while(i < str.size())
	{
		if (*p == '?')
			questCount++;
		p++;
		i++;
	}

	return questCount;
}

short QuestCount3(std::string str)
{
	short questCount = 0;

	for (char ch : str)
	{
		if (ch == '?')
			questCount++;
	}

	return questCount;
}	

int main(int argc, const char* arfgv[])
{ 
	std::string cmdLineInput{CmdLineInputToString(argc, arfgv)};

	std::cout << "This line was passed as an argument: " << cmdLineInput << "\n";

	std::vector<short (*)(std::string)> funcVec{&QuestCount1, &QuestCount2, &QuestCount3};

	for (auto func : funcVec)
	{
		std::cout << "quest " << (*func)(cmdLineInput) << ";\n";
	}
}
