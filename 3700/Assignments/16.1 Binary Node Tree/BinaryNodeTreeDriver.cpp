/*
	Name: BinaryNodeTreeDriver
	Copyright: 2025
	Author: Yu Jiang
	Date: 6/7/25
	Description: The C++ implementation file for the BinaryNodeTreeDriver class.
*/

#include <iostream>
#include "BinaryNodeTree.h"
#include <cassert>

std::string booleanStr(const bool &b)
{
	return b ? "YES" : "NO";
}

void visitNode(int &item)
{
	std::cout << item << std::endl;
}

void printTreePreorder(const BinaryNodeTree<int> &tree)
{
	std::cout << "------Preorder Tree------" << std::endl;
	std::cout << "Empty: " << booleanStr(tree.isEmpty()) << std::endl;
	std::cout << "Height: " << tree.getHeight() << std::endl;
	std::cout << "Count: " << tree.getNumberOfNodes() << std::endl;
	tree.preorderTraverse(visitNode);
	std::cout << "------End Preorder Tree------" << std::endl;
}

void printTreeInorder(const BinaryNodeTree<int> &tree)
{
	std::cout << "------Inorder Tree------" << std::endl;
	std::cout << "Empty: " << booleanStr(tree.isEmpty()) << std::endl;
	std::cout << "Height: " << tree.getHeight() << std::endl;
	std::cout << "Count: " << tree.getNumberOfNodes() << std::endl;
	tree.inorderTraverse(visitNode);
	std::cout << "------End Inorder Tree------" << std::endl;
}

void printTreePostorder(const BinaryNodeTree<int> &tree)
{
	std::cout << "------Postorder Tree------" << std::endl
		<< "Empty: " << booleanStr(tree.isEmpty()) << std::endl
		<< "Height: " << tree.getHeight() << std::endl
		<< "Count: " << tree.getNumberOfNodes() << std::endl;
	tree.postorderTraverse(visitNode);
	std::cout << "------End Postorder Tree------" << std::endl;
}

bool printRootData(const BinaryNodeTree<int> &tree)
{
	if (tree.isEmpty())
		return false;
	std::cout << "Root Data: "
		<< tree.getRootData() << std::endl;
	return true;
}

bool getEntry(const BinaryNodeTree<int> &tree, const int &entry)
{
	int result;
	try
	{
		result = tree.getEntry(entry);
	}
	catch (std::logic_error &ex)
	{
		return false;
	}
	std::cout << "Get Entry: "
		<< result << std::endl;
	return true;
}

bool clear(BinaryNodeTree<int> &tree)
{
	tree.clear();
	return tree.isEmpty();
}

bool testRootData(BinaryNodeTree<int> &tree)
{
	tree.setRootData(999);
	return tree.getRootData() == 999;
}

int main()
{
	BinaryNodeTree<int> tree;
	printTreeInorder(tree);
	assert(tree.add(1));
	assert(tree.add(2));
	assert(tree.add(3));
	assert(tree.add(4));
	assert(tree.add(5));
	assert(tree.add(6));
	printTreePreorder(tree);
	assert(printRootData(tree));
	assert(testRootData(tree));
	assert(printRootData(tree));
	assert(tree.contains(2));
	assert(getEntry(tree, 2));
	assert(clear(tree));
	std::cout << std::endl << "Test Complete";
	return 0;
}
