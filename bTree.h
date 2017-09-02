#ifndef bTree_H
#define bTree_H

#include <iostream>
using std::ostream;


class treeNode
{
public:
	treeNode();
	treeNode(int val);
	int value;
	treeNode * left;
	treeNode * right;

	bool operator== (treeNode other);
	friend ostream &operator<<(ostream &out, treeNode &A);
};

class BinaryTree
{
public:
	BinaryTree();
	treeNode * root;

	bool virtual insert(treeNode *t);
	bool remove(int x);
	treeNode *find(int x);
	bool populate(unsigned int numNodes);

protected:
	unsigned int numNodes;

	treeNode *findHelper(treeNode *root, int val);
};

class BST : public BinaryTree
{
	bool insert(treeNode *t);
};

#endif /* bTree_H*/