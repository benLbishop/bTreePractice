#include "stdafx.h"
#include "bTree.h"
#include <climits>
#include <time.h>
#include <random>

treeNode::treeNode()
{
	value = INT_MIN;
}

treeNode::treeNode(int _value)
{
	value = _value;
}

bool treeNode::operator==(treeNode other)
{
	return (this->value == other.value);
}

ostream &operator<<(std::ostream &out, treeNode *t)
{
	out << t->value << std::endl;
	return out;
}


BinaryTree::BinaryTree()
{
	root = new treeNode();
	numNodes = 1;
}

bool BinaryTree::insert(treeNode *t)
{
	/*
	Moves right or left randomly until we find a null child, then insert
	*/
	std::default_random_engine eng(time(0));
	treeNode *node = root;

	bool INSERT_FLAG = false;
	while (!INSERT_FLAG){
		int x = eng();			//generate random int
		if (x % 2 == 0){
			//move or insert left
			if (node->left != NULL){
				node = node->left;
			}
			else {
				node->left = t;
				++numNodes;
				INSERT_FLAG = true;
			}
		}
		else {
			//move or insert right
			if (node->right != NULL){
				node = node->right;
			}
			else {
				node->right = t;
				++numNodes;
				INSERT_FLAG = true;
			}
		}
	}
	return 0;
}

treeNode *BinaryTree::find(int val)
{
	/*
	look for the input val as a treeNode value. return the treeNode if found.
	Maybe the parent as well, for delete?
	*/
	return findHelper(root, val);
}
treeNode* BinaryTree::findHelper(treeNode *node, int val)
{
	if (node == NULL) return NULL;
	if(node->value == val) return node;

	findHelper(node->left, val);
	findHelper(node->right, val);
	return NULL;
}

bool BinaryTree::remove(int val)
{
	treeNode *node_to_remove = find(val);
	if (node_to_remove == NULL) return false;		//treeNode not found
	delete node_to_remove;
	return true;
}

bool BinaryTree::populate(unsigned int numNodes)
{
	std::default_random_engine eng(time(0));

	for (unsigned int i = 0; i < numNodes; ++i){
		int x = eng() % 100;
		treeNode *newNode = new treeNode(x);
		insert(newNode);
	}
	return true;
}

bool BST::insert(treeNode *t)
{
	/*
	Insert and preserve the BST property, i.e.
	if t->val <= root, put in left subtree. else put in right subtree
	*/
	//std::cout << "calling derived class" << std::endl;
	treeNode *x = root;
	bool INSERT_FLAG = false;
	while (!INSERT_FLAG){
		//check to see which way to move
		bool move_left = t->value <= x->value;
		if (move_left){
			if (x->left == NULL){
				x->left = t;
				++numNodes;
				INSERT_FLAG = true;
			}
			else{
				x = x->left;
			}
		}
		else {
			//go right
			if (x->right == NULL){
				x->right = t;
				++numNodes;
				INSERT_FLAG = true;
			}
			else{
				x = x->right;
			}
		}
	}
	return true;
}