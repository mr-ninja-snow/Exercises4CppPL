#include <iostream>
#include <string>

int main(int argc, const char* arfgv[])
{ 
	std::string cmdLineInput;

	for (int i = 1; i < argc; i++)
	{
		cmdLineInput += " ";
		cmdLineInput += arfgv[i];
	}

	std::cout << "This line was passed as an argument: " << cmdLineInput << "\n";

	short quest_count = 0;
	for (int i = 0; i < cmdLineInput.size(); ++i)
	{
		if(cmdLineInput[i] == '?')
			quest_count++;
	}

	std::cout << "quest " << quest_count << ";\n";

	quest_count = 0;
	const char* p = cmdLineInput.c_str();
	int i = 0;
	while(i < cmdLineInput.size())
	{
		if (*p == '?')
			quest_count++;
		p++;
		i++;
	}

	std::cout << "quest " << quest_count << ";\n";

	quest_count = 0;
	for (char ch : cmdLineInput)
	{
		if (ch == '?')
			quest_count++;
	}
	std::cout << "quest " << quest_count << ";\n";
}
