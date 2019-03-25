#include "Tree.hpp"
#include <cstdlib>
#include <iostream>


using namespace std;
using  ariel::Node;
using ariel::Tree;

ariel::Node::Node(int val): value(val), left(nullptr), right(nullptr), parent(nullptr) {}

ariel::Tree::Tree()
{
	this->Root = nullptr;
	this->Size = 0;
}

/* this function put a new Node in the tree and increas its size by 1*/
void ariel::Tree::insert(int val)
{
	if (this->Root == nullptr) //if root is null than the tree is empty and the new Node will be the root
	{
		Node *node = new Node(val);
		this->Root = node;
		this->Size++;
	}

	else if (this->contains(val) == false) { //if the Node is alredy in the tree than the function return false

		Node *newNode = new Node(val);  //the Node with the value of the number we want to insert
		Node *parent = findParent(val); //the parent of that Node

		if (parent->value > val) { //if parent value is bigger than the new Node will ne his left child else he will be the right child

			parent->left = newNode;
		}
		else {

			parent->right = newNode;
		}
		this->Size++;
	}
	else {
		cout << "ERROR: Node is already exists"<<endl;
	}

}

/*Given value, remove the Node that keep's this value*/
void ariel::Tree::remove(int val)
{
	this->deleteNode(Root, val);
}

/*return the size of the tree*/
int ariel::Tree::size()
{
	return this->Size;
}

/* this function check if the number is already exists in the tree and return true or false */
bool ariel::Tree::contains(int val)
{
	Node* current = this->find(val);
	if (current == nullptr) //if current is null than the number is not in the tree
		return false;
	else
		return true;
}

/*this function return the root of the tree*/
int ariel::Tree::root()
{
	return this->Root->value;
}

/* this function return the value of the parent of val*/
int ariel::Tree::parent(int val)
{
	if (val == this->Root->value) //if val is the value of the root than it has no parent
	{
		cout << "the value is root" << endl;
		return -1;
	}
	else {

		Node* temp = find(val);
		if (temp != nullptr) {
			return temp->parent->value;
		}
		else {
			cout << "there is no such number in the tree"<< endl;
			return -1;
		}
	}
}

/* this function return the left child of the Node with the value val*/
int ariel::Tree::left(int val)
{
	if (this->contains(val)) //if the number val is in the tree enter
	{
		Node* temp = this->find(val); //the Node withe the value of val
		if (temp->left == nullptr) //if temp left child is null than print massage error
		{
			cout << "there is no left child for this Node" << endl;
				return -1;
		}
		else
		{
			return temp->left->value;
		}
	}
	else {
		cout << "there is no such value in the tree" << endl;
			return -1;
	}
}

/* this function return the the value of the right child of val*/
int ariel::Tree::right(int val)
{
	if (this->contains(val)) // if val is in the tree than enter
	{
		Node* temp = this->find(val);  //temp is the Node with the value of val
		if (temp->right == nullptr) //if temp right child is null than enter
		{
			cout << "there is no right child for this Node" << endl;
			return -1;
		}
		else
		{
			return temp->right->value;
		}
	}
	else {
		cout << "there is no such value in the tree" << endl;
		return -1;
	}
}

/*Given a binary tree, print its nodes in inorder*/
void ariel::Tree::print()
{
	printer(this->Root); 
}

/*Given a value, find the Node that keep it if exists*/
Node* ariel::Tree::find(int val)
{
	Node* current = Root;
	/*based on binary search,
	if val is greater then current's value we set to right child
	if val is lower then current's value we set to the left child
	if this value is not exist we return nullptr*/
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

/*  finds the supposed to be parent of a new node.*/
Node* ariel::Tree::findParent(int val)
{
	Node* current = Root;
	Node* parent = Root;

	/*this loop goes till current is null
	we set current to be the root. 
	parent set to be current position every iteration. and current:
	if val is greater then current's value,current set to be the right child
	if val is lower then current's value,current set to be the left child*/
	while (current != nullptr) 
	{
		if (current->value > val)
		{
			parent = current;
			current = current->left;
		}
		else if (current->value < val)
		{
			parent = current;
			current = current->right;
		}
	}
	return parent;
}

/* www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder */
void ariel::Tree::printer(Node* node)
{
	if (node == nullptr)
		return;

	/* first recur on left child */
	printer(node->left);

	/* then print the data of node */
	cout << node->value << " ";

	/* now recur on right child */
	printer(node->right);
}

/* hwww.geeksforgeeks.org/binary-search-tree-set-2-delete */
Node * ariel::Tree::deleteNode(Node * root, int k)
{
	// Base case 
	if (root == NULL)
		return root;

	// Recursive calls for ancestors of 
	// node to be deleted 
	if (root->value> k) {
		root->left = deleteNode(root->left, k);
		return root;
	}
	else if (root->value < k) {
		root->right = deleteNode(root->right, k);
		return root;
	}

	// We reach here when root is the node 
	// to be deleted. 

	// If one of the children is empty 
	if (root->left == NULL) {
		Node* temp = root->right;
		delete root;
		this->Size--;
		return temp;
	}
	else if (root->right == NULL) {
		Node* temp = root->left;
		delete root;
		this->Size--;
		return temp;
	}

	// If both children exist 
	else {

		Node* succParent = root->right;

		// Find successor 
		Node *succ = root->right;
		while (succ->left != NULL) {
			succParent = succ;
			succ = succ->left;
		}

		// Delete successor.  Since successor 
		// is always left child of its parent 
		// we can safely make successor's right 
		// right child as left of its parent. 
		succParent->left = succ->right;

		// Copy Successor Data to root 
		root->value = succ->value;

		// Delete Successor and return root 
		delete succ;
		this->Size--;
		return root;
	}
}