//#include <string>
#include <cstring>
#include <vector>
#include <algorithm>    // std::copy
// #include <array>
// #include <stdlib.h>     /* srand, rand */
// #include <time.h>       /* time */
// #include "timer.hpp"
// #include "helper.hpp"

#ifndef VLIB_H
#define VLIB_H

namespace exercise_8{

	struct Tnode {
		// std::string word;
		// int count;
		char* word;

		Tnode* left;
		Tnode* right;

		Tnode() : word(nullptr), left(nullptr), right(nullptr)
		{}

		Tnode(const char initWord[]) : left(nullptr), right(nullptr)
		{
			size_t sizeOfWord = std::strlen(initWord);//sizeof(initWord)/sizeof(char);//std::strlen(initWord);
			word = new char[sizeOfWord];
			std::copy_n(initWord, sizeOfWord, word);
		}

		~Tnode()
		{
			if (word)
				delete [] word;
		}
	};

	bool addATnodeToTree(Tnode&, const char word[], const int levelCount = 0);
	Tnode* createAndFillInTnode(const char word[]);
	int getTnodeCount(const Tnode& tree, int nodeCount = 0);
	int getTnodeTreeDepthInLevels(const Tnode& tree, const int currnetLevel = 0);
	std::string insertIndentation(const int numberOfTabs);
	std::ostream& operator<<(std::ostream& o, const Tnode& tNode);
	void retriveAllTnodeTreeWords(const Tnode& tNode, std::vector<std::string>& words);
	void printTnodeContentInAlphabeticalOrder(const Tnode& tree);
	void printTnodeTree(const Tnode& tree);

	// bool addATnodeToTree(Tnode&, const std::string, const int levelCount = 0);
	// int getTnodeCount(const Tnode& tree, int nodeCount = 0);
	// Tnode* createAndFillInTnode(const std::string word, const int levelCount);
	// void printTnodeTree(const Tnode& tree);
	// std::string insertIndentation(const int numberOfTabs);
	// int getTnodeTreeDepthInLevels(const Tnode& tree, const int currnetLevel = 0);
	// void printTnode(const Tnode& tNode, const int levelLeftToPrint = -1);

	// std::ostream& operator<<(std::ostream& o, const Tnode& tNode);
	// void retriveAllTnodeTreeWords(const Tnode& tNode, std::vector<std::string>& words);
	// void printTnodeContentInAlphabeticalOrder(const Tnode& tree);

}

#endif