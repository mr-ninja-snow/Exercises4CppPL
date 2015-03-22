#ifndef VS_B_TREE_HPP
#define VS_B_TREE_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>    // std::copy

namespace VSBTree
{

	struct BinTreeNode {

		char* word;

		BinTreeNode* leftNode;
		BinTreeNode* rightNode;

		BinTreeNode(const char* initWord) : leftNode(nullptr), rightNode(nullptr)
		{
			size_t sizeOfWord = std::strlen(initWord);

			word = new char[sizeOfWord];
			std::copy_n(initWord, sizeOfWord, word);
		}

		~BinTreeNode()
		{
			if ( rightNode )
			{
				delete rightNode;
			}

			if ( leftNode )
			{
				delete leftNode;
			}

			std::cout << "Debug : Deleting " << word << "\n";
			if ( word )
			{
				delete [] word;
			}
		}
	};

	void addNodeToTree(BinTreeNode& node, const char* word);
	// // BinTreeNode* createAndFillInBinTreeNode(const char word[]);
	// int getBinTreeNodeCount(const BinTreeNode& tree, int nodeCount = 0);
	// int getBinTreeNodeTreeDepthInLevels(const BinTreeNode& tree, const int currnetLevel = 0);
	// std::string insertIndentation(const int numberOfTabs);
	// std::ostream& operator<<(std::ostream& o, const BinTreeNode& BintreeNode);
	// void retriveAllBinTreeNodeTreeWords(const BinTreeNode& BintreeNode, std::vector<std::string>& words);
	// void printBinTreeNodeContentInAlphabeticalOrder(const BinTreeNode& tree);
	// void printBinTreeNodeTree(const BinTreeNode& tree);

}

#endif