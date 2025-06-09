/*
	Name: BinaryNodeTree
	Copyright: 2025
	Author: Yu Jiang
	Date: 6/7/25
	Description: The C++ implementation file for the BinaryNodeTree class.
*/

#ifndef BINARYNODETREE_HPP
#define BINARYNODETREE_HPP
#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include <iostream>
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(
	std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
						getHeightHelper(subTreePtr->getRightChildPtr()));
}

template <class ItemType>
int BinaryNodeTree<ItemType>::
getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	if (!subTreePtr)
		return 0;
	return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())
		+ getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

template <class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(
	std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
	std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;
	else
	{
		auto leftPtr = subTreePtr->getLeftChildPtr();
		auto rightPtr = subTreePtr->getRightChildPtr();
		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		} // end if
		return subTreePtr;
	} // end if
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::
moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
	// Skipped
	return nullptr;
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::
removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
			const ItemType target, bool &success)
{
	return subTreePtr;
}

template <class ItemType>
auto BinaryNodeTree<ItemType>::
findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
		const ItemType &target, bool &success) const
{
	success = false;
	if (!treePtr)
	{
		ItemType dummyItem;
		return dummyItem;
	}
	if (treePtr->getItem() == target)
	{
		success = true;
		return treePtr->getItem();
	}
	auto leftResult = findNode(treePtr->getLeftChildPtr(), target, success);
	if (success)
		return leftResult;
	return findNode(treePtr->getRightChildPtr(), target, success);
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>>
BinaryNodeTree<ItemType>::copyTree(
	const std::shared_ptr
	<BinaryNode<ItemType>> oldTreeRootPtr)
const
{
	std::shared_ptr<BinaryNode<ItemType>> newTreePtr;
	// Copy tree nodes during a preorder traversal
	if (oldTreeRootPtr != nullptr)
	{
		// Copy node
		newTreePtr = std::make_shared<BinaryNode<ItemType>>
			(oldTreeRootPtr->getItem(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
	} // end if
	return newTreePtr;
} // end copyTree

template <class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(
	std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		subTreePtr->setLeftChildPtr(nullptr);
		subTreePtr->setRightChildPtr(nullptr);
		subTreePtr.reset();
		subTreePtr = nullptr;
	} // end if
}

template <class ItemType>
void BinaryNodeTree<ItemType>::
preorder(void visit(ItemType &),
		std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if (treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
	} // end if
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorder(
	void visit(ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if (treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	} // end if
}

template <class ItemType>
void BinaryNodeTree<ItemType>::
postorder(void visit(ItemType &),
		std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if (treePtr != nullptr)
	{
		postorder(visit, treePtr->getLeftChildPtr());
		postorder(visit, treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
	} // end if
}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
{}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType &rootItem)
	: rootPtr(
		std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{}

template <class ItemType>
BinaryNodeTree<ItemType>::
BinaryNodeTree(const ItemType &rootItem,
				const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
				const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
	: rootPtr(std::
		make_shared<BinaryNode<ItemType>>(rootItem,
										copyTree(leftTreePtr->rootPtr),
										copyTree(rightTreePtr->rootPtr)))
{}

// Public Functions

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(
	const BinaryNodeTree<ItemType> &treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
}

template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
	return rootPtr == nullptr;
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
	return getHeightHelper(rootPtr);
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const
{
	if (isEmpty())
		throw PrecondViolatedExcep("Tree is empty");
	return rootPtr->getItem();
}

template <class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType &newData)
{
	if (isEmpty())
		add(newData);
	else rootPtr->setItem(newData);
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType &newData)
{
	auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType &data)
{
	// Skipped
	return false;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
	destroyTree(rootPtr);
	rootPtr = nullptr;
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType &anEntry) const
{
	if (isEmpty())
		throw NotFoundException("Tree is empty.");
	auto success = false;
	auto value = findNode(rootPtr, anEntry, success);
	if (!success)
		throw NotFoundException("The entry doesn't exist in tree.");
	return value;
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType &anEntry) const
{
	if (isEmpty())
		return false;
	auto success = false;
	findNode(rootPtr, anEntry, success);
	return success;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType &)) const
{
	preorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType &)) const
{
	inorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType &)) const
{
	postorder(visit, rootPtr);
}

template <class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::
operator=(const BinaryNodeTree &rightHandSide)
{
	rootPtr = copyTree(rightHandSide);
	return *this;
}
#endif // BINARYNODETREE_HPP
