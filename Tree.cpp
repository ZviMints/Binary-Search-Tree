#include "Tree.hpp"
using namespace ariel;
#include <iomanip> // used for setw ( BASED ON: https://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way )
/** default Constructor **/
Tree::Tree() {
	_root = NULL;
	_size = 0;
}
/** default Destructor  **/
Tree::~Tree() {
	freeSubtree(_root);
	cout << "Tree Deleted." << endl;
}
/** this method is responsible to free an substree that passed by input **/
void Tree::freeSubtree(node* ptr)
{
	if( ptr != NULL )
	{
		freeSubtree(ptr->right);
		freeSubtree(ptr->left);
		delete ptr;
	}
}
Tree::node* Tree::allocateLeaf(int key) {
	node* temp = new node;
	temp->key = key;
	temp->right = NULL;
	temp->left = NULL;
	temp->parent = NULL;
	return temp;
}
/** This method is responsible to insert value to the BS Tree. **/
Tree::node* Tree::insert(int key,node* ptr) {
	if(ptr == NULL)
	{
		ptr = allocateLeaf(key);
		_size++;
	}
	else if(key > ptr->key)
	{
		ptr->right = insert(key,ptr->right);
		ptr->right->parent = ptr;
	}
	else if(key < ptr->key)
	{
		ptr->left = insert(key,ptr->left);
		ptr->left->parent = ptr;
	}
	else // its equals
		throw std::runtime_error("The input value correspond to inserted value in the tree.");
	return ptr;
}
/** This method is responsible to return the minimum node in the input subtree **/
Tree::node* Tree::MinValueSubtree(node* root)
{
	node* current = root;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

Tree::node* Tree::contains(int key,node* ptr)
{
	if( ptr == NULL || ptr->key == key ) return ptr;
	else if ( key > ptr->key ) return contains(key, ptr->right);
	else return contains(key, ptr->left);
}
/** This method is responsible to insert value to the BS Tree. **/
void Tree::insert(int key){
	if(_root == NULL) { _root = allocateLeaf(key); _size++; }
	else insert(key,_root);
}
/** This method is responsible to remove value from the BS Tree. **/
void Tree::remove(node* ptr){

		node* parent = ptr->parent;

		if(ptr->left == NULL && ptr->right == NULL) // Case 1: No Children
		{
			if(parent == NULL) {
				this->_root = NULL;
			}
			else
			{
				if(parent->key < ptr->key) // ptr is right children of parent
				{
					parent->right = NULL;
				}
				else
				{
					parent->left = NULL;
				}
			}
			delete ptr;
		}
		else if(ptr->left == NULL) // Case 2: One Right Children
		{
			if(parent == NULL)
			{
				this->_root = ptr->right;
				this->_root->parent = NULL;

			}
			else
			{
				if(parent->key < ptr->key) // ptr is right children of parent
				{
					parent->right = ptr->right;
					ptr->right->parent = parent;
				}
				else
				{
					parent->left = ptr->right;
					ptr->right->parent = parent;
				}
			}
			delete ptr;
		}
		else if(ptr->right == NULL) // Case 2: One Left Children
		{
			if(parent == NULL)
			{
				this->_root = ptr->left;
				this->_root->parent = NULL;
			}
			else
			{
				if(parent->key < ptr->key) // ptr is right children of parent
				{
					parent->right = ptr->left;
					ptr->left->parent = parent;
				}
				else
				{
					parent->left = ptr->left;
					ptr->left->parent = parent;
				}
			}
			delete ptr;
		}
		else // Case 3: Two Children
		{
			node* temp = MinValueSubtree(ptr->right);
			int _key = temp->key;
			remove(temp);
			ptr->key = _key;
		}
}
/** This method is responsible to remove value from the BS Tree. **/
void Tree::remove(int key){
	node* ans = contains(key,_root);
	if(ans == NULL || this->_root == NULL )
		throw std::runtime_error ("no such key to delete");
	else
	{
		remove(ans);
		_size--;
	}
}
/** This method is responsible to return the current size ( number of nodes in the tree ) **/
unsigned int Tree::size(){ return _size; }
/** This method is responsible to return the current root data **/
int Tree::root() {
	if(_root == NULL) throw std::runtime_error("_root is NULL.");
	else return _root->key;
}
/** This method is responsible to return true iff key can be found in the BS Tree. **/
bool Tree::contains(int key){
	if ( contains(key,_root) == NULL ) return false;
	else return true;
}
/** this method gets as input an key, and output her parent node value in the tree **/
int Tree::parent(int key){
	node* temp = contains(key,_root);
	if(temp == NULL) throw std::runtime_error("there no such node that fit the input key value");
	if(temp->parent != NULL )
		return temp->parent->key;
	else
		throw std::runtime_error("there no parent node");}

/** this method gets as input an key, and output her right node value in the tree **/
int Tree::right(int key){
	node* temp = contains(key,_root);
	if(temp == NULL) throw std::runtime_error("there no such node that fit the input key value");
	if(temp->right != NULL )
		return temp->right->key;
	else
		throw std::runtime_error("there no right node");
}

/** this method gets as input an key, and output her left node value in the tree **/
int Tree::left(int key){
	node* temp = contains(key,_root);
	if(temp == NULL) throw std::runtime_error("there no such node that fit the input key value");
	if(temp->left != NULL )
		return temp->left->key;
	else
		throw std::runtime_error("there no left node");
}
/** this method is responsible to call inorder() method in order to print the current state of the tree **/
void Tree::print(){
	postorder(_root,0);
}
/** This method is responsible to print the current BST in `PostOrder`
 * BASED ON: https://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way
 */
void Tree::postorder(node* ptr, int indent)
{
	if(ptr != NULL) {
		if(ptr->right) {
			postorder(ptr->right, indent+4);
		}
		if (indent) {
			cout << setw(indent) << ' ';
		}
		if (ptr->right) cout<<" /\n" << setw(indent) << ' ';
		cout<< ptr->key << "\n ";
		if(ptr->left) {
			cout << setw(indent) << ' ' <<" \\\n";
			postorder(ptr->left, indent+4);
		}
	}
}
