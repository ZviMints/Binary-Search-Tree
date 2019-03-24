#include <iostream>
using namespace std;
namespace ariel {
class Tree {
	struct node {
			int key;
			node* right;
			node* left;
			node* parent;
	};
	node* _root;
	unsigned int _size;
	node* insert(int key,node* ptr);
	node* contains(int key,node* ptr);
	void freeSubtree(node* ptr);
	node* allocateLeaf(int key);
	node* MinValueSubtree(node* root);
	void remove(node* ptr);
public:
	Tree();
	~Tree();
	void insert(int key);
	void remove(int key);
	unsigned int size();
	bool contains(int key);
	int parent(int key);
	int right(int key);
	int root();
	int left(int key);
	void print();
	void postorder(node* ptr, int indent);
};
}
