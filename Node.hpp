#include <iostream>

using namespace std;

class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node* parent;

	Node(int);
	int getValue();
};