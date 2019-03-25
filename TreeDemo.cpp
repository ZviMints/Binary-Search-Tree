#include <iostream>
#include <string>
#include "Tree.hpp"
using namespace ariel;

#define LOG(x) std::cout << x << std::endl;
int main()
{
	try {
		Tree tree;
		tree.insert(3);
		tree.insert(5);
		tree.insert(7);
		tree.insert(-1);
		tree.insert(16);
		tree.insert(0);
		tree.insert(-5);
		tree.insert(-9);
		tree.remove(0);
		tree.remove(-1);
		LOG("Tree size is: " << tree.size());
		tree.print();
	   }
	   catch (std::exception& exp) { std::cout << exp.what() << std::endl; }
}
