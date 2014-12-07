#include <iostream>		//std::cout, std::cerr
// #include <array>
#include "vlib.hpp"


int main(int argc, const char* arfgv[])
{

	exercise_8::Tnode tree;

	exercise_8::addATnodeToTree(tree, "1");
	exercise_8::addATnodeToTree(tree, "2");
	exercise_8::addATnodeToTree(tree, "3");
	exercise_8::addATnodeToTree(tree, "4");
	exercise_8::addATnodeToTree(tree, "5");
	exercise_8::addATnodeToTree(tree, "6");
	exercise_8::addATnodeToTree(tree, "7");
	exercise_8::addATnodeToTree(tree, "8");
	exercise_8::addATnodeToTree(tree, "9");
	exercise_8::addATnodeToTree(tree, "10");
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

	return 0;
}
