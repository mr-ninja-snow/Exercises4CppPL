#include <string>
// #include <array>
// #include <stdlib.h>     /* srand, rand */
// #include <time.h>       /* time */
// #include "timer.hpp"
// #include "helper.hpp"

#ifndef VLIB_H
#define VLIB_H

namespace exercise_8{

	struct Tnode {
		std::string word;
		int count;

		Tnode* left;
		Tnode* right;

		Tnode(std::string initWord = "", int initCount = 0) : word(initWord), count(initCount), left(nullptr), right(nullptr)
		{}
	};

	bool addATnodeToTree(Tnode&, const std::string, const int levelCount = 0);
	int getTnodeCount(const Tnode& tree, int nodeCount = 0);
	Tnode* createAndFillInTnode(const std::string word, const int levelCount);
	void printTnodeTree(const Tnode& tree);
	std::string insertIndentation(const int numberOfTabs);
	int getTnodeTreeDepthInLevels(const Tnode& tree, const int currnetLevel = 0);
	void printTnode(const Tnode& tNode, const int levelLeftToPrint = -1);

	std::ostream& operator<<(std::ostream& o, const Tnode& tNode);

	/* using CFT = int(const void*, const void*);
	int intCmp(const void* a, const void* b);

	void ssort(void* base, size_t n, size_t sz, CFT cmp);
	void newSsort(void* base, size_t n, size_t sz, CFT cmp);

	using SSF = void(void*, size_t, size_t, CFT);
	template<typename T, std::size_t SIZE>
	float sort(std::array<T, SIZE> fooArray, SSF sortFunc)
	{
		vTimer::Timer t;
		std::cout <<  "\nBefore sorting:\n\t" << fooArray;

		t.startTimer();
		sortFunc(fooArray.data(), fooArray.size(), sizeof(T), exercise_7::intCmp);
		t.stopTimer();

		std::cout <<  "\nAfter sorting:\n\t" << fooArray;
		std::cout << "duration: " << t.getResult() << "s" << std::endl;

		return t.getResult();
	}

	template<std::size_t SIZE>
	void generateArrayWithRandomNumbers(std::array<int, SIZE>& fooArray)
	{
		 // initialize random seed: 
		srand (time(NULL));

		for (auto& elem : fooArray)
		{
			elem = rand() % 1000;
		}
	}*/

}

#endif