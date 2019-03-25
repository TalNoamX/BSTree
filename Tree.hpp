
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

		Node* find(int val);
		Node* findParent(int val);
		void printer(Node* root);
		Node* deleteNode(Node* root, int k);

	public:
		Tree();
		void insert(int val);
		void remove(int val);
		int size();
		bool contains(int val);
		int root();
		int parent(int val);
		int left(int val);
		int right(int val);
		void print();
	};
}