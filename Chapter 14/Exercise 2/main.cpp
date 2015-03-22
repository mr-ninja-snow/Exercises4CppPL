#include <iostream>

#include "VSBTree.hpp"

int main(int argc, char* argv[])
{
	VSBTree::BinTreeNode* root = new VSBTree::BinTreeNode{ "test" };

	VSBTree::addNodeToTree( *root, "car");
	VSBTree::addNodeToTree( *root, "cat");

	delete root;

	return 0;
}
