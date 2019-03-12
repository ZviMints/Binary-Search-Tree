#include "BST.h"
/** default Constructor **/
BST::BST() {
	_root = NULL;
	_size = 0;
}
/** default Destructor  **/
BST::~BST() {
	freeSubtree(_root);
	cout << "Tree Deleted." << endl;
}
/** this method is responsible to free an substree that passed by input **/
void BST::freeSubtree(node* ptr)
{
	if( ptr != NULL )
	{
		double key = ptr->key;
		freeSubtree(ptr->right);
		freeSubtree(ptr->left);
		delete ptr;

		cout << key << " Deleted." << endl;
		_size-- ;
	}

}
BST::node* BST::allocateLeaf(double key) {
	node* temp = new node;
	temp->key = key;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}
BST::node* BST::insert(double key,node* ptr) {
	if(ptr == NULL)
	{
		ptr = allocateLeaf(key);
		_size++;
	}
	else if(key > ptr->key)
	{
		ptr->right = insert(key,ptr->right);
	}
	else if(key < ptr->key)
		ptr->left = insert(key,ptr->left);
	else // its equals
		throw string("The input value correspond to inserted value in the tree.");
	return ptr;
}
void BST::remove(double key,node* ptr) {
	// **** NEED TO IMPLEMENT
}
BST::node* BST::contains(double key,node* ptr)
{
	if( ptr == NULL || ptr->key == key ) return ptr;
	else if ( key > ptr->key ) return contains(key, ptr->right);
	else return contains(key, ptr->left);
}
/** This method is responsible to insert value to the BS Tree. **/
void BST::insert(double key){
	if(_root == NULL) _root = allocateLeaf(key);
	else insert(key,_root);
}
void BST::remove(double key){ remove(key,_root);}

/** This method is responsible to return the current size ( number of nodes in the tree ) **/
size_t BST::size(){ return _size; }
/** This method is responsible to return the current root data **/
double BST::root() {
	if(_root == NULL) throw string("_root is NULL.");
	else return _root->key;
}
/** This method is responsible to return true iff key can be found in the BS Tree. **/
bool BST::contains(double key){
	return ( contains(key,_root) == NULL );
}
double BST::parent(double key){
	// **** NEED TO IMPLEMENT
}

/** this method gets as input an key, and output her right node value in the tree **/
double BST::right(double key){
	node* temp = contains(key,_root);
	if(temp->right != NULL )
		return temp->right->key;
	else
		throw string("there no right node");
}
/** this method gets as input an key, and output her left node value in the tree **/
double BST::left(double key){
	node* temp = contains(key,_root);
	if(temp->left != NULL )
		return temp->left->key;
	else
		throw string("there no left node");
}
/** this method is responsible to call inorder() method in order to print the current state of the tree **/
void BST::print(){
	inorder(_root);
}
/** This method is responsible to print the current BST in `inOrder` **/
void BST::inorder(node* ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr->left);
		cout << ptr->key << endl;
		inorder(ptr->right);
	}
}



