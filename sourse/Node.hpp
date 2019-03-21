#include <iostream>

using namespace std;


struct Node 
{
	int   value;
	Node* left;
	Node* right;
	Node* parent;

	Node(int);
};