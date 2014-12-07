#include <iostream>		//std::cout, std::cerr
// #include <algorithm>	//std::sort
#include "vlib.hpp"

namespace exercise_8{

	bool addATnodeToTree(Tnode& tree, const std::string word, const int levelCount)
	{
		int currentLevelCount = (levelCount == 0) ? 1 : levelCount;

		std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Entered tree level " << levelCount << "\n\n";

		if (tree.word == "")
		{
			tree = Tnode(word, currentLevelCount);

			return true;
		}

		//tree.right = (tree.right == nullptr) ? createAndFillInTnode(word, currentLevelCount) : tree.right;

		if (tree.right == nullptr)
		{
			std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Created new tnode for " << word << " on right side of tree level " << currentLevelCount << "\n\n";
			tree.right = createAndFillInTnode(word, currentLevelCount);

			return true;
		}

		if (tree.left == nullptr)
		{
			std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Created new tnode for " << word << " on left side of tree level " << currentLevelCount << "\n\n";
			tree.left = createAndFillInTnode(word, currentLevelCount);

			return true;
		}

		// int ncr, ncl;

		//debug
		int ncr = getTnodeCount(*(tree.right));

		// std::cout << "nodes on the right - " << ncr << "\n";

		int ncl = getTnodeCount(*(tree.left));
		// std::cout << "nodes on the left - " << ncl << "\n";

		//if (ncr = (getTnodeCount(*(tree.right))) < (ncl = getTnodeCount(*(tree.left))))
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
		// if (addATnodeToTree(*(tree.right), word, levelCount + 1))
		// {
		// 	return true;
		// }

		// if (addATnodeToTree(*(tree.left), word, levelCount + 1))
		// {
		// 	return true;
		// }

		// return false;
	}

	int getTnodeCount(const Tnode& tree, int nodeCount)
	{
		// std::cout << "nodeCount - " << nodeCount << "\n";
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

	Tnode* createAndFillInTnode(const std::string word, const int levelCount)
	{
		Tnode* newTNode = new Tnode;

		newTNode->word = word;
		newTNode->count = levelCount;

		newTNode->right = nullptr;
		newTNode->left = nullptr;

		return newTNode;
	}

	void printTnodeTree(const Tnode& tree)
	{
		int treeDepth = getTnodeTreeDepthInLevels(tree);

		/*std::cout << insertIndentation(treeDepth) << tree << "\n";

		int numberOfSubNodes = 2;
		Tnode** tNodesToPrint = new Tnode*[numberOfSubNodes];

		tNodesToPrint[0] = tree.left;
		tNodesToPrint[1] = tree.right;

		--treeDepth;
		std::cout << insertIndentation(treeDepth) << *tNodesToPrint[0];
		std::cout << insertIndentation(treeDepth) << *tNodesToPrint[1];
		std::cout << "\n";

*/

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
			std::cout << "???" << indent << std::endl;
			if (printArray1)
			{
				for (int i = 0; i < sizeOfTnodesToPrint1; ++i)
					if (tNodesToPrint1[i])
						std::cout << insertIndentation(indent) << *tNodesToPrint1[i];
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
				std::cout << "free 1\n";

				printArray1 = false;
				continue;
			}
			if (!printArray1)
			{
				for (int i = 0; i < sizeOfTnodesToPrint2; ++i)
					if (tNodesToPrint2[i])
						std::cout << insertIndentation(indent) << *tNodesToPrint2[i] ;
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
				std::cout << "free 2\n";

				printArray1 = true;
				continue;
			}


/*
			Tnode** tNodesToPrint2 = new Tnode*[numberOfSubNodes * 2];
			int index = 0;
			for (int i = 0; i < numberOfSubNodes; ++i)
			{
				tNodesToPrint2[index++] = tNodesToPrint[i]->left;
				tNodesToPrint2[index++] = tNodesToPrint[i]->right;
			}
			numberOfSubNodes *= 2;

			for (int i = 0; i < numberOfSubNodes; ++i)
				std::cout << insertIndentation(i) << *tNodesToPrint2[i];*/
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

	void printTnode(Tnode& tNode, int levelLeftToPrint)
	{

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
		// copy(arr.cbegin(), arr.cend(), std::ostream_iterator<T>(o, " "));
		o << tNode.word << "    ";

		return o;
	}


	/*Tnode* newTNode = new Tnode;

			newTNode->word = word;
			newTNode->count = levelCount;

			newTNode->right = nullptr;
			newTNode->left = nullptr;

			tree.right = newTNode;*/


	/*using CFT = int(const void*, const void*);

	int intCmp(const void* a, const void* b)
	{
		const int* _a = reinterpret_cast<const int*>(a);
		const int* _b = reinterpret_cast<const int*>(b);

		return (*_a < *_b) ? -1 : ((*_a > *_b) ? 1 : 0);
	}

	void ssort(void* base, size_t n, size_t sz, CFT cmp)
	{
		for (int gap=n/2; 0<gap; gap/=2)
		{
			for (int i=gap; i!=n; i++)
				for (int j=i-gap; 0<=j; j-=gap)
				{
					char* b = static_cast<char*>(base);     // necessary cast
					char* pj = b+j*sz;                 // &base[j]
					char* pjg = b+(j+gap)*sz;          // &base[j+gap]

					if (cmp(pjg,pj)<0)           // swap base[j] and base[j+gap]:
					{
						for (int k=0; k!=sz; k++)
						{
							char temp = pj[k];

							pj[k] = pjg[k];
							pjg[k] = temp;
						}
					}
				}
		}
	}

	void newSsort(void* base, size_t n, size_t sz, CFT cmp)
	{
		std::sort(reinterpret_cast<int*>(base), reinterpret_cast<int*>(base) + n + 1);
	}*/

}//namespace exercise_7
