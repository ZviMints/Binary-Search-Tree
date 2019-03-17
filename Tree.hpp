#include <iostream>
using namespace std;
namespace ariel {
class Tree {
	struct node {
			double key;
			node* right;
			node* left;
			node* parent;
	};
	node* _root;
	unsigned int _size;
	node* insert(double key,node*& ptr);
	node* remove(double key,node* ptr);
	node* contains(double key,node* ptr);
	void freeSubtree(node* ptr);
	node* allocateLeaf(double key);
	node* MinValueSubtree(node* root);
public:
	Tree();
	~Tree();
	void insert(double key);
	void remove(double key);
	unsigned int size();
	bool contains(double key);
	double parent(double key);
	double right(double key);
	double root();
	double left(double key);
	void print();
	void postorder(node* ptr, int indent);
};
}
