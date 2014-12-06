#include <iostream>		//std::cout, std::cerr
// #include <array>
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{

	exercise_8::Tnode tree;

	exercise_8::addATnodeToTree(tree, "hello");
	exercise_8::addATnodeToTree(tree, "to");
	exercise_8::addATnodeToTree(tree, "this");
	exercise_8::addATnodeToTree(tree, "world");
	exercise_8::addATnodeToTree(tree, "to");
	exercise_8::addATnodeToTree(tree, "this");
	exercise_8::addATnodeToTree(tree, "world");
	exercise_8::addATnodeToTree(tree, "to");
	// exercise_8::addATnodeToTree(tree, "this");
	// exercise_8::addATnodeToTree(tree, "world");
	// exercise_8::addATnodeToTree(tree, "to");
	// exercise_8::addATnodeToTree(tree, "this");
	// exercise_8::addATnodeToTree(tree, "world");
	// exercise_8::addATnodeToTree(tree, "to");
	// exercise_8::addATnodeToTree(tree, "this");
	// exercise_8::addATnodeToTree(tree, "world");

	std::cout << "This is the depth of the tree " << exercise_8::getTnodeTreeDepthInLevels(tree) << std::endl;

	return 0;
}
