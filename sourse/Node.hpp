#include <iostream>

namespace ariel
{


	struct Node
	{
		int   value;
		Node* left;
		Node* right;
		Node* parent;

		Node(int);
	};
}