#include <iostream>

#include "Tree.h"
int main()
{
	try {
		Tree tree;
		tree.insert(3);
		cout << tree.size() << endl;
		tree.insert(5);
		cout << tree.size() << endl;
		tree.insert(7);
		cout << tree.size() << endl;
		tree.insert(-1);
		tree.insert(16);
		tree.insert(0);
		tree.insert(-5);
		tree.insert(6.2);
		tree.insert(-1.3);
		tree.insert(-9);
		tree.insert(0.1);
		cout << tree.size() << endl;
		tree.remove(6.2);
		tree.remove(0);
		tree.remove(-1);
		cout << tree.size() << endl;
		tree.remove(3.3);
	}
	catch (string & s) { cout << s << endl; }

}
