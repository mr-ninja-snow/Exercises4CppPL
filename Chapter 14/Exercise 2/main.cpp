#include <iostream>
#include <exception>      // std::exception

#include "VSBTree.hpp"

int main(int argc, char* argv[])
{
	VSBTree::BinTreeNode* root = new VSBTree::BinTreeNode{ "test" };

	VSBTree::addNodeToTree( *root, "car");
	VSBTree::addNodeToTree( *root, "cat");

	const VSBTree::BinTreeNode* n = nullptr;
	try
	{
		n = VSBTree::find( *root, "bat");
		std::cout << "Found word!\n";
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
	}

	delete root;

	return 0;
}
