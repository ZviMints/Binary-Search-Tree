#include <iostream>
using namespace std;
class BST {
	struct node {
		double key;
		node* right;
		node* left;
	};

	node* _root;
	size_t _size;
	node* insert(double key,node* ptr);
	void remove(double key,node* ptr);
	node* contains(double key,node* ptr);
	void freeSubtree(node* ptr);
	node* allocateLeaf(double key);
public:
	BST();
	~BST();
	void insert(double key);
	void remove(double key);
	size_t size();
	bool contains(double key);
	double parent(double key);
	double right(double key);
	double root();
	double left(double key);
	void print();
	void inorder(node* ptr);
};
