#include "Node.hpp"

Node::Node(int val)
{
	this->value = val;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;

}

int Node::getValue()
{
	return this->value;
}
