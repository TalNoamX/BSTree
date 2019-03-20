#include "Tree.hpp"



void Tree::insert(int val)
{
	
	if (this->Root == NULL) {

		Node *node = new Node(val);
		this->Root = node;
		this->size++;

	}
	else if (this->contains == false) {

		Node *newNode = new Node(val);
		Node *corrent = find(val);

		if (corrent->value > val) {

			corrent->left = newNode;
		}
		else {

			corrent->right = newNode;
		}
		this->size++;
	}
	else {
		cout << "ERROR: Node is already exists";
	}

}

void Tree::remove(int)
{

}

int Tree::size()
{
	return this->size;
}

bool Tree::contains(int)
{
	return false;
}

int Tree::root()
{
	return this->Root->value;
}

int Tree::parent(int)
{
	return 0;
}

int Tree::left(int)
{
	return 0;
}

int Tree::right(int)
{
	return 0;
}

void Tree::print()
{
}

Node * Tree::find(int)
{
	return nullptr;
}
