#include <iostream>		//std::cout, std::cerr
// #include <array>
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{

	exercise_8::Tnode tree;

	exercise_8::addATnodeToTree(tree, "x");
	exercise_8::addATnodeToTree(tree, "l");
	exercise_8::addATnodeToTree(tree, "m");
	exercise_8::addATnodeToTree(tree, "z");
	exercise_8::addATnodeToTree(tree, "j");
	exercise_8::addATnodeToTree(tree, "n");
	exercise_8::addATnodeToTree(tree, "o");
	exercise_8::addATnodeToTree(tree, "c");
	exercise_8::addATnodeToTree(tree, "b");
	exercise_8::addATnodeToTree(tree, "a");
	exercise_8::addATnodeToTree(tree, "this");
	exercise_8::addATnodeToTree(tree, "world");
	exercise_8::addATnodeToTree(tree, "to");
	exercise_8::addATnodeToTree(tree, "this");
	exercise_8::addATnodeToTree(tree, "world");
	exercise_8::addATnodeToTree(tree, "to");
	exercise_8::addATnodeToTree(tree, "this");
	 exercise_8::addATnodeToTree(tree, "world");

	std::cout << "This is the depth of the tree " << exercise_8::getTnodeTreeDepthInLevels(tree) << std::endl;

	exercise_8::printTnodeTree(tree);

	std::cout << "\n\n\n";

	printTnodeContentInAlphabeticalOrder(tree);

	return 0;
}
