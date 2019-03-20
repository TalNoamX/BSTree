#include "Node.hpp"
#include <vector>
#include <map>

class Tree {
public:
	Node* Root;
	int size;
	

	void insert(int);
	void remove(int);
	int size();
	bool contains(int);
	int root();
	int parent(int);
	int left(int);
	int right(int);
	void print();

private:
	Node* find(int);
	
};