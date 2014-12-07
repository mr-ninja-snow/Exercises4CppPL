#include <iostream>		//std::cout, std::cerr
#include "vlib.hpp"

namespace exercise_8{

	bool addATnodeToTree(Tnode& tree, const char word[], const int levelCount)
	{
		int currentLevelCount = (levelCount == 0) ? 1 : levelCount;

		std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Entered tree level " << levelCount << "\n\n";

		if (tree.word == nullptr)
		{
			size_t sizeOfWord = std::strlen(word);//sizeof(word)/sizeof(char);
			tree.word = new char[sizeOfWord];
			std::copy_n(word, sizeOfWord, tree.word);

			return true;
		}

		if (tree.right == nullptr)
		{
			std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Created new tnode for '" << word << "' on right side of tree level " << currentLevelCount << "\n\n";
			tree.right = createAndFillInTnode(word);

			return true;
		}

		if (tree.left == nullptr)
		{
			std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Created new tnode for '" << word << "' on left side of tree level " << currentLevelCount << "\n\n";
			tree.left = createAndFillInTnode(word);

			return true;
		}

		int ncr = getTnodeCount(*(tree.right));
		int ncl = getTnodeCount(*(tree.left));

		if (ncr < ncl)
		{
			std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Drill down to the rigth on level " << currentLevelCount << " --->(" << ncl << "|" << ncr <<")\n\n";
			addATnodeToTree(*(tree.right), word, currentLevelCount + 1);
			return true;
		}
		else
		{
			std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Drill down to the left on level " << currentLevelCount << " <---(" << ncl << "|" << ncr <<")\n\n";
			addATnodeToTree(*(tree.left), word, currentLevelCount + 1);
			return true;
		}
	}

	int getTnodeCount(const Tnode& tree, int nodeCount)
	{
		if (tree.right != nullptr)
		{
			nodeCount = getTnodeCount(*(tree.right), ++nodeCount);
		}

		if (tree.left != nullptr)
		{
			nodeCount = getTnodeCount(*(tree.left), ++nodeCount);
		}

		return nodeCount;
	}

	Tnode* createAndFillInTnode(const char word[])
	{
		Tnode* newTNode = new Tnode;

		size_t sizeOfWord = std::strlen(word);//sizeof(word)/sizeof(char);
		(*newTNode).word = new char[sizeOfWord];
		std::copy_n(word, sizeOfWord + 1, (*newTNode).word);

		std::cout << "CREATED - " << (*newTNode).word  << " from - " << word << "\n";

		return newTNode;
	}

	void printTnodeTree(const Tnode& tree)
	{
		int treeDepth = getTnodeTreeDepthInLevels(tree);

		size_t sizeOfTnodesToPrint1 = 0;
		const Tnode** tNodesToPrint1;

		size_t sizeOfTnodesToPrint2 = 0;
		const Tnode** tNodesToPrint2;

		bool printArray1 = true;

		sizeOfTnodesToPrint1 = 1;
		tNodesToPrint1 = new const Tnode*[sizeOfTnodesToPrint1];
		tNodesToPrint1[0] = &tree;

		for (int indent = treeDepth; indent >= 0; --indent)
		{
			if (printArray1)
			{
				for (int i = 0; i < sizeOfTnodesToPrint1; ++i)
					if (tNodesToPrint1[i])
						std::cout << insertIndentation(indent) << (*tNodesToPrint1[i]).word;
					else
						std::cout << insertIndentation(indent) << "-    ";
				std::cout << "\n";

				sizeOfTnodesToPrint2 = sizeOfTnodesToPrint1 * 2;
				tNodesToPrint2 = new const Tnode*[sizeOfTnodesToPrint2];

				int index = 0;
				for (int i = 0; i < sizeOfTnodesToPrint1; ++i)
				{
					if (tNodesToPrint1[i])
					{
						tNodesToPrint2[index++] = tNodesToPrint1[i]->left;
						tNodesToPrint2[index++] = tNodesToPrint1[i]->right;
					}
				}
				delete [] tNodesToPrint1;
				tNodesToPrint1 = nullptr;

				printArray1 = false;
				continue;
			}
			if (!printArray1)
			{
				for (int i = 0; i < sizeOfTnodesToPrint2; ++i)
					if (tNodesToPrint2[i])
						std::cout << insertIndentation(indent) << (*tNodesToPrint2[i]).word;
					else
						std::cout << insertIndentation(indent) << "-    ";
				std::cout << "\n";

				sizeOfTnodesToPrint1 = sizeOfTnodesToPrint2 * 2;
				tNodesToPrint1 = new const Tnode*[sizeOfTnodesToPrint1];

				int index = 0;
				for (int i = 0; i < sizeOfTnodesToPrint2; ++i)
				{
					if (tNodesToPrint2[i])
					{
						tNodesToPrint1[index++] = tNodesToPrint2[i]->left;
						tNodesToPrint1[index++] = tNodesToPrint2[i]->right;
					}
				}
				delete [] tNodesToPrint2;
				tNodesToPrint2 = nullptr;

				printArray1 = true;
				continue;
			}
		}

		if (tNodesToPrint1)
			delete [] tNodesToPrint1;

		if (tNodesToPrint2)
			delete [] tNodesToPrint2;
	}

	int getTnodeTreeDepthInLevels(const Tnode& tree, const int currnetLevel)
	{
		int maxDepthR = currnetLevel;
		int maxDepthL = currnetLevel;

		if (tree.right != nullptr)
			maxDepthR = getTnodeTreeDepthInLevels(*(tree.right), currnetLevel + 1);

		if (tree.left != nullptr)
			maxDepthL = getTnodeTreeDepthInLevels(*(tree.left), currnetLevel + 1);

		return (maxDepthR > maxDepthL) ? maxDepthR : maxDepthL;
	}

	std::string insertIndentation(const int numberOfTabs)
	{
		std::string str;

		for (int i = 0; i < numberOfTabs; ++i)
		{
			str += "    ";
		}

		return str;
	}

	std::ostream& operator<<(std::ostream& o, const Tnode& tNode)
	{
		o << tNode.word << "    ";

		return o;
	}

	void printTnodeContentInAlphabeticalOrder(const Tnode& tree)
	{
		std::vector<std::string> words;

		retriveAllTnodeTreeWords(tree, words);

		std::sort(words.begin(), words.end());

		for(auto el : words)
			std::cout << el << "\n";
	}

	void retriveAllTnodeTreeWords(const Tnode& tNode, std::vector<std::string>& words)
	{
		words.push_back(tNode.word);

		if (tNode.right != nullptr)
			retriveAllTnodeTreeWords(*(tNode.right), words);

		if (tNode.left != nullptr)
			retriveAllTnodeTreeWords(*(tNode.left), words);

	}

}//namespace exercise_8
