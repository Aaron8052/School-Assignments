/*
	Name: Linked List
	Copyright: 2025
	Author: Yu Jiang
	Date: 4/24/25
	Description: The C++ implementation for the LinkedList class.
*/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include "LinkedList.h"
#include <cassert>

template <class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{} // end default constructor

template <class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &aList) :
	itemCount(aList.itemCount)
{
	Node<ItemType>* origChainPtr = aList.headPtr; // Points to original chain
	if (origChainPtr == nullptr)
		headPtr = nullptr; // Original list is empty
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr; // Points to new last node
		origChainPtr = origChainPtr->getNext(); // Advance original pointer
		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();
			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();
			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		} // end while
		newChainPtr->setNext(nullptr); // Flag end of chain
	} // end if
} // end copy constructor

template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
} // end destructor

template <class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template <class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}

template <class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType &newEntry)
{
	if (newPosition < 1 || newPosition > itemCount + 1)
		return false;
	Node<ItemType>* newNode = new Node<ItemType>(newEntry);
	headPtr = insertChain(newPosition, newNode, headPtr);
	return true;
}

template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::
insertChain(int position, Node<ItemType>* newNode, Node<ItemType>* subChainPtr)
{
	if (position == 1)
	{
		newNode->setNext(subChainPtr);
		itemCount++;
		return newNode;
	}
	Node<ItemType>* afterPtr =
		insertChain(position - 1, newNode, subChainPtr->getNext());
	subChainPtr->setNext(afterPtr);
	return subChainPtr;
}

template <class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	if (!headPtr || position < 1 || position > itemCount) return false;
	headPtr = removeRecur(headPtr, headPtr->getNext(), position);
	return true;
}

template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::removeRecur(Node<ItemType>* currNode,
												Node<ItemType>* subChainPtr, int position)
{
	if (position == 1)
	{
		delete currNode;
		itemCount--;
		return subChainPtr;
	}
	Node<ItemType>* next =
		removeRecur(subChainPtr, subChainPtr->getNext(), position - 1);
	currNode->setNext(next);
	return currNode;
}

template <class ItemType>
void LinkedList<ItemType>::clear()
{
	clearChain(headPtr);
}

template <class ItemType>
void LinkedList<ItemType>::clearChain(Node<ItemType>* currNode)
{
	if (itemCount < 1) return;
	Node<ItemType>* nextNode = currNode->getNext();
	delete currNode;
	itemCount--;
	clearChain(nextNode);
}

template <class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
	// Enforce precondition
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		std::string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcep(message));
	}
}

template <class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType &newEntry)
{
	bool ableToSet = (position >= 1) && (position <= itemCount);
	if (ableToSet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		nodePtr->setItem(newEntry);
	}
	else
	{
		std::string message = "replace() called with an invalid position.";
		throw(PrecondViolatedExcep(message));
	} // end if
} // end replace

template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	assert((position >= 1) && (position <= itemCount));
	return getNodeAtRecur(headPtr, position);
}

template <class ItemType>
Node<ItemType>* LinkedList<ItemType>
::getNodeAtRecur(Node<ItemType>* currNode, int position) const
{
	if (position == 1) return currNode;
	return getNodeAtRecur(currNode->getNext(), position - 1);
}

//  End of implementation file.
#endif
