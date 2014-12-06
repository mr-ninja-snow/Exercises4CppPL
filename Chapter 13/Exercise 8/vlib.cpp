#include <iostream>		//std::cout, std::cerr
// #include <algorithm>	//std::sort
#include "vlib.hpp"

namespace exercise_8{

	bool addATnodeToTree(Tnode& tree, const std::string word, int levelCount)
	{
		levelCount = (levelCount == 0) ? 1 : levelCount;

		std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Entered tree level " << levelCount << "\n\n";

		if (tree.word == "")
		{
			tree = Tnode(word, levelCount);

			return true;
		}

		//tree.right = (tree.right == nullptr) ? createAndFillInTnode(word, levelCount) : tree.right;

		if (tree.right == nullptr)
		{
			std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Created new tnode on right side of tree level " << levelCount << "\n\n";
			tree.right = createAndFillInTnode(word, levelCount);

			return true;
		}

		if (tree.left == nullptr)
		{
			std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Created new tnode on left side of tree level " << levelCount << "\n\n";
			tree.left = createAndFillInTnode(word, levelCount);

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
			std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Drill down to the rigth on level " << levelCount << " --->(" << ncl << "|" << ncr <<")\n\n";
			addATnodeToTree(*(tree.right), word, levelCount + 1);
			return true;
		}
		else
		{
			std::cout << __FILE__ << '|' << __FUNCTION__ << '|' <<__LINE__ << "|Drill down to the left on level " << levelCount << " <---(" << ncl << "|" << ncr <<")\n\n";
			addATnodeToTree(*(tree.left), word, levelCount + 1);
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

	int getTnodeCount(Tnode& tree, int nodeCount)
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

	Tnode* createAndFillInTnode(const std::string word, int levelCount)
	{
		Tnode* newTNode = new Tnode;

		newTNode->word = word;
		newTNode->count = levelCount;

		newTNode->right = nullptr;
		newTNode->left = nullptr;

		return newTNode;
	}

	void printTnodeTree(Tnode& tree)
	{
		int treeDepth = getTnodeTreeDepthInLevels(tree);

		
	}

	int getTnodeTreeDepthInLevels(Tnode& tree, int currnetLevel)
	{
		static int maxDepth = 0;

		maxDepth = (maxDepth < currnetLevel) ? currnetLevel : maxDepth;

		if (tree.right != nullptr)
			getTnodeTreeDepthInLevels(*(tree.right), currnetLevel + 1);

		if (tree.left != nullptr)
			getTnodeTreeDepthInLevels(*(tree.left), currnetLevel + 1);

		return maxDepth;
	}

	void printTnode(Tnode& tNode, int levelLeftToPrint)
	{

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
