
#include "mylib.h"


struct data
{
	int i;
	int j;
};

int main(int argc, const char* arfgv[])
{ 
	/*Seasons s = Seasons::spring;

	std::cout << "\n\nThe season is: " << s << "\n";
	++s;
	std::cout << "\n\nThe season is: " << s << "\n";
	--s;
	std::cout << "\n\nThe season is: " << s << "\n";
	
	std::cin >> s;
	std::cout << "\n\nThe season is: " << s << "\n";
	std::cin >> s;
	std::cout << "\n\nThe season is: " << s << "\n";*/

	data* d = new data {1, 33};

	std::cout << d->i << " " << d->j << "\n";
//	std::string findThis {"ab"};
//	std::string foo {"badkfkcababkfldrab"};
//	char bar[] {"badkfkcababkfldrababab"};

//	std::cout << findThis << "was found " << CountOccurrences(findThis, foo) << " in the std::string\n";
//	std::cout << findThis << "was found " << CountOccurrences(findThis, bar) << " in the C style string\n";
	
}
