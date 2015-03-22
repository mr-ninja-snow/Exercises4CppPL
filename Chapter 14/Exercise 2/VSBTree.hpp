#ifndef VS_B_TREE_HPP
#define VS_B_TREE_HPP

#include <iostream>
#include <string>

namespace VSBTree
{

	struct node_s
	{
		std::string strData;
		node_s* rightNode;
		node_s* leftNode;
	};

}

#endif