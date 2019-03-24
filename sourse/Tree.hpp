#include "Node.hpp"
#include <vector>

namespace ariel
{

	class Tree {
	private:
		Node* Root;
		int size;

		Node* find(int);
		Node* findParent(int);
		Node* printer(Node* root);
		Node* deleteNode(Node* root, int k);

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
}