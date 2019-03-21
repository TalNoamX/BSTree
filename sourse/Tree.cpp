#include "Tree.hpp"



void Tree::insert(int val)
{
	if (this->Root == NULL) 
	{
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

bool Tree::contains(int val)
{
	Node* current = this->find(val);
	if (current == nullptr)
		return false;
	else
		return true;
}

int Tree::root()
{
	return this->Root->value;
}

int Tree::parent(int val)
{
	if (val == this->Root->value)
	{
		cout << "the value is root";
		return -1;
	}
	else {

		Node* temp = find(val);
		if (contains(val)) {
			return temp->parent->value;
		}
		else {
			cout << "there is no such number in the tree";
			return -1;
		}
	}
}

int Tree::left(int val)
{
	if (this.contains(val))
	{
		Node* temp = this->find(val);
		return temp->left;
	}
	else {
		cout << "there is no such value in the tree"
			return -1;
	}
}

int Tree::right(int val)
{
	if (this->contains(val))
	{
		Node* temp = this->find(val);
		return temp->right;
	}
	else
	{
		cout << "there is no such value in the tree"
			return -1;
	}
}

void Tree::print()
{
}

Node* Tree::find(int val)
{
	Node* current = Root;

	while (current != nullptr) 
	{

		if (current->value == val)
		{
			return current;
		}

		else if (current->value > val)
		{
			current = current->left;
		}
		else if (current->value < val)
		{
			current = current->right;
		}
	}
	return nullptr;
}
