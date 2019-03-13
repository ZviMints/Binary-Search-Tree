#include "BST.h"
int main()
{
	try {
	BST tree;
	tree.insert(3);
	tree.insert(5);
	tree.insert(7);
	tree.insert(-1);
	tree.insert(16);
	tree.insert(0);
	tree.insert(-5);
	tree.insert(6.2);
	tree.insert(-1.3);
	tree.insert(-9);
	tree.print();
	}
	catch (string & s) { cout << s << endl; }

}
