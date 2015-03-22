#include "VSBTree.hpp"

#include <iostream>

namespace
{
	// inline void TraceFunction(const char* msg)
	// {
	// 	std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << " " << msg << "\n";
	// }
}


namespace VSBTree
{

	void addNodeToTree(BinTreeNode& node, const char* word)
	{

		if (node.rightNode == nullptr)
		{
			node.rightNode = new BinTreeNode{ word };
			return;
		}

		if (node.leftNode == nullptr)
		{
			node.leftNode = new BinTreeNode{ word };
			return;
		}

		const int ncr = getBinTreeNodeCount(*(node.rightNode));
		const int ncl = getBinTreeNodeCount(*(node.leftNode));

		if (ncr < ncl)
		{
			addNodeToTree(*(node.rightNode), word);
		}
		else
		{
			addNodeToTree(*(node.leftNode), word);
		}
	}

	// int getBinTreeNodeCount(const BinTreeNode& tree, int nodeCount)
	// {
	// 	if (tree.rightNode != nullptr)
	// 	{
	// 		nodeCount = getBinTreeNodeCount(*(tree.rightNode), ++nodeCount);
	// 	}

	// 	if (tree.leftNode != nullptr)
	// 	{
	// 		nodeCount = getBinTreeNodeCount(*(tree.leftNode), ++nodeCount);
	// 	}

	// 	return nodeCount;
	// }

	// // BinTreeNode* createAndFillInNode(const char const* word)
	// // {
	// // 	BinTreeNode* newTNode = new BinTreeNode{ word };

	// // 	// size_t sizeOfWord = std::strlen(word);
	// // 	// (*newTNode).word = new char[sizeOfWord];
	// // 	// std::copy_n(word, sizeOfWord + 1, (*newTNode).word);

	// // 	// std::cout << "CREATED - " << (*newTNode).word  << " from - " << word << "\n";

	// // 	return newTNode;
	// // }

	// void printBinTreeNodeTree(const BinTreeNode& tree)
	// {
	// 	int treeDepth = getBinTreeNodeTreeDepthInLevels(tree);

	// 	size_t sizeOfBinTreeNodesToPrint1 = 0;
	// 	const BinTreeNode** tNodesToPrint1;

	// 	size_t sizeOfBinTreeNodesToPrint2 = 0;
	// 	const BinTreeNode** tNodesToPrint2;

	// 	bool printArray1 = true;

	// 	sizeOfBinTreeNodesToPrint1 = 1;
	// 	tNodesToPrint1 = new const BinTreeNode*[sizeOfBinTreeNodesToPrint1];
	// 	tNodesToPrint1[0] = &tree;

	// 	for (int indent = treeDepth; indent >= 0; --indent)
	// 	{
	// 		if (printArray1)
	// 		{
	// 			for (int i = 0; i < sizeOfBinTreeNodesToPrint1; ++i)
	// 				if (tNodesToPrint1[i])
	// 					std::cout << insertIndentation(indent) << (*tNodesToPrint1[i]).word;
	// 				else
	// 					std::cout << insertIndentation(indent) << "-    ";
	// 			std::cout << "\n";

	// 			sizeOfBinTreeNodesToPrint2 = sizeOfBinTreeNodesToPrint1 * 2;
	// 			tNodesToPrint2 = new const BinTreeNode*[sizeOfBinTreeNodesToPrint2];

	// 			int index = 0;
	// 			for (int i = 0; i < sizeOfBinTreeNodesToPrint1; ++i)
	// 			{
	// 				if (tNodesToPrint1[i])
	// 				{
	// 					// tNodesToPrint2[index++] = tNodesToPrint1[i]->left;
	// 					// tNodesToPrint2[index++] = tNodesToPrint1[i]->right;
	// 				}
	// 			}
	// 			delete [] tNodesToPrint1;
	// 			tNodesToPrint1 = nullptr;

	// 			printArray1 = false;
	// 			continue;
	// 		}
	// 		if (!printArray1)
	// 		{
	// 			for (int i = 0; i < sizeOfBinTreeNodesToPrint2; ++i)
	// 				if (tNodesToPrint2[i])
	// 					std::cout << insertIndentation(indent) << (*tNodesToPrint2[i]).word;
	// 				else
	// 					std::cout << insertIndentation(indent) << "-    ";
	// 			std::cout << "\n";

	// 			sizeOfBinTreeNodesToPrint1 = sizeOfBinTreeNodesToPrint2 * 2;
	// 			tNodesToPrint1 = new const BinTreeNode*[sizeOfBinTreeNodesToPrint1];

	// 			int index = 0;
	// 			for (int i = 0; i < sizeOfBinTreeNodesToPrint2; ++i)
	// 			{
	// 				if (tNodesToPrint2[i])
	// 				{
	// 					// tNodesToPrint1[index++] = tNodesToPrint2[i]->left;
	// 					// tNodesToPrint1[index++] = tNodesToPrint2[i]->right;
	// 				}
	// 			}
	// 			delete [] tNodesToPrint2;
	// 			tNodesToPrint2 = nullptr;

	// 			printArray1 = true;
	// 			continue;
	// 		}
	// 	}

	// 	if (tNodesToPrint1)
	// 		delete [] tNodesToPrint1;

	// 	if (tNodesToPrint2)
	// 		delete [] tNodesToPrint2;
	// }

	// int getBinTreeNodeTreeDepthInLevels(const BinTreeNode& tree, const int currnetLevel)
	// {
	// 	int maxDepthR = currnetLevel;
	// 	int maxDepthL = currnetLevel;

	// 	if (tree.rightNode != nullptr)
	// 		maxDepthR = getBinTreeNodeTreeDepthInLevels(*(tree.rightNode), currnetLevel + 1);

	// 	if (tree.leftNode != nullptr)
	// 		maxDepthL = getBinTreeNodeTreeDepthInLevels(*(tree.leftNode), currnetLevel + 1);

	// 	return (maxDepthR > maxDepthL) ? maxDepthR : maxDepthL;
	// }

	// std::string insertIndentation(const int numberOfTabs)
	// {
	// 	std::string str;

	// 	for (int i = 0; i < numberOfTabs; ++i)
	// 	{
	// 		str += "    ";
	// 	}

	// 	return str;
	// }

	// std::ostream& operator<<(std::ostream& o, const BinTreeNode& tNode)
	// {
	// 	o << tNode.word << "    ";

	// 	return o;
	// }

	// void printBinTreeNodeContentInAlphabeticalOrder(const BinTreeNode& tree)
	// {
	// 	std::vector<std::string> words;

	// 	retriveAllBinTreeNodeTreeWords(tree, words);

	// 	std::sort(words.begin(), words.end());

	// 	for(auto el : words)
	// 		std::cout << el << "\n";
	// }

	// void retriveAllBinTreeNodeTreeWords(const BinTreeNode& tNode, std::vector<std::string>& words)
	// {
	// 	words.push_back(tNode.word);

	// 	if (tNode.rightNode != nullptr)
	// 		retriveAllBinTreeNodeTreeWords(*(tNode.rightNode), words);

	// 	if (tNode.leftNode != nullptr)
	// 		retriveAllBinTreeNodeTreeWords(*(tNode.leftNode), words);

	// }

}