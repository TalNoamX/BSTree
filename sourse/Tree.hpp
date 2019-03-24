#include "Node.hpp"
#include <vector>

class Tree {
private:
	Node* Root;
	int size;

	Node* find(int);
	Node* findParent(int);

public:
	void insert(int);
	void remove(int);
	int size();
	bool contains(int);
	int root();
	int parent(int);
	int left(int);
	int right(int);
	void print();
};