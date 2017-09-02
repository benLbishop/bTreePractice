// binaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bTree.h"
#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
using std::cout;
using std::endl;

void traverseTree(treeNode *root)
{
	if (root == NULL) return;
	traverseTree(root->left);
	cout << "cur node: " << root->value << endl;
	traverseTree(root->right);
	return;
}

int main(int argc, char * argv[])
{
	auto start_time = std::chrono::high_resolution_clock::now();
	BinaryTree my_tree = BST();
	my_tree.populate(100);
	treeNode * walker = my_tree.root;
	traverseTree(walker);
	auto end_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> x = end_time - start_time;
	cout << "elapsed time is " << x.count() << endl;
	return 0;
}
