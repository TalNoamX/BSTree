
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

	class Tree {
	private:
		Node* Root;
		int Size;

		Node* find(int);
		Node* findParent(int);
		void printer(Node* root);
		Node* deleteNode(Node* root, int k);

	public:
		Tree();
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