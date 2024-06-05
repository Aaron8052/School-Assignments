/*
	Name: 
	Copyright: 2024
	Author: Yu Jiang
	Date: 05/06/24 11:48
	Description: 
*/

#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

// Main test driver
int main(int argc, char** argv) {
	IntBinaryTree tree;
	tree.insertNode(20);
	tree.insertNode(7);
	tree.insertNode(0);
	tree.insertNode(40);
	tree.insertNode(50);
	tree.insertNode(-3);
	tree.insertNode(30);
	cout << "Inorder traversal: \n";
	tree.displayInOrder();
	cout << "Preorder traversal: \n";
	tree.displayPreOrder();
	cout << "Postorder traversal: \n";
	tree.displayPostOrder();
	return 0;
}