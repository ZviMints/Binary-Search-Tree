#include "Tree.h"

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
		_size-- ;
	}

}
Tree::node* Tree::allocateLeaf(double key) {
	node* temp = new node;
	temp->key = key;
	temp->right = NULL;
	temp->left = NULL;
	temp->parent = NULL;
	return temp;
}
/** This method is responsible to insert value to the BS Tree. **/
Tree::node* Tree::insert(double key,node* ptr) {
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
		throw string("The input value correspond to inserted value in the tree.");
	return ptr;
}
/** This method is responsible to remove value from the BS Tree. **/
Tree::node* Tree::remove(double key,node* ptr) {

	// Base cases
	if(ptr == NULL) return ptr;

	else if(key > ptr->key) ptr->right = remove(key,ptr->right);

	else if(key < ptr->key) ptr->left = remove(key,ptr->left);

	// key == ptr->key && ptr != NULL
	else
	{
		// No child
		if(ptr->right == NULL && ptr->left == NULL)
		{
			free(ptr);
			ptr = NULL;
		}
		// One child
		else if(ptr->right == NULL)
		{
			node* temp = ptr;
			ptr = ptr->left;
			delete temp;
		}
		else if(ptr->left == NULL)
		{
			node* temp = ptr;
			ptr = ptr->right;
			delete temp;
		}
		else {
			// Two child
			node* temp = MinValueSubtree(ptr->right);
			ptr->key = temp->key;
			ptr->right = remove(temp->key,ptr->right);
		}
	}
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

Tree::node* Tree::contains(double key,node* ptr)
{
	if( ptr == NULL || ptr->key == key ) return ptr;
	else if ( key > ptr->key ) return contains(key, ptr->right);
	else return contains(key, ptr->left);
}
/** This method is responsible to insert value to the BS Tree. **/
void Tree::insert(double key){
	if(_root == NULL) { _root = allocateLeaf(key); _size++; }
	else
		insert(key,_root);
}
/** This method is responsible to remove value from the BS Tree. **/
void Tree::remove(double key){
	if(contains(key) == 1) throw string ("no such key to delete");
	else { remove(key,_root); _size--; }
}

/** This method is responsible to return the current size ( number of nodes in the tree ) **/
size_t Tree::size(){ return _size; }
/** This method is responsible to return the current root data **/
double Tree::root() {
	if(_root == NULL) throw string("_root is NULL.");
	else return _root->key;
}
/** This method is responsible to return true iff key can be found in the BS Tree. **/
bool Tree::contains(double key){
	return ( contains(key,_root) == NULL );
}
/** this method gets as input an key, and output her parent node value in the tree **/
double Tree::parent(double key){
	node* temp = contains(key,_root);
	if(temp == NULL) throw string("there no such node that fit the input key value");
	if(temp->parent != NULL )
		return temp->parent->key;
	else
		throw string("there no parent node");}

/** this method gets as input an key, and output her right node value in the tree **/
double Tree::right(double key){
	node* temp = contains(key,_root);
	if(temp == NULL) throw string("there no such node that fit the input key value");
	if(temp->right != NULL )
		return temp->right->key;
	else
		throw string("there no right node");
}

/** this method gets as input an key, and output her left node value in the tree **/
double Tree::left(double key){
	node* temp = contains(key,_root);
	if(temp == NULL) throw string("there no such node that fit the input key value");
	if(temp->left != NULL )
		return temp->left->key;
	else
		throw string("there no left node");
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
