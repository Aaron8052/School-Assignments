/*
    Name: LinkedSet Implementations
    Copyright: 2025
    Author: Yu Jiang
    Date: 03/28/2025
    Description: The C++ implementations file for the LinkedSet class.
*/

//#include "LinkedSet.h"

template <class ItemType>
LinkedSet<ItemType>::LinkedSet()
{}

template <class ItemType>
LinkedSet<ItemType>::~LinkedSet()
{
	clear();
}

template <class ItemType>
int LinkedSet<ItemType>::getCurrentSize() const
{
	return count;
}

template <class ItemType>
bool LinkedSet<ItemType>::isEmpty() const
{
	return count <= 0;
}

template <class ItemType>
bool LinkedSet<ItemType>::add(const ItemType& newEntry)
{
	if (isEmpty())
	{
		headPtr = new Node<ItemType>(newEntry);
		count = 1;
		return true;
	}
	if (contains(newEntry))
		return false;
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, headPtr);
	headPtr = newNodePtr;
	count++;
	return true;
}

template <class ItemType>
bool LinkedSet<ItemType>::remove(const ItemType& anEntry)
{
	// return if empty or headPtr is null
	if (isEmpty() || !headPtr) return false;
	Node<ItemType>* nextNodePtr = nullptr;
	// If the entry is the first item
	if (headPtr->getItem() == anEntry)
	{
		nextNodePtr = headPtr->getNext();
		delete headPtr;
		headPtr = nextNodePtr;
		count--;
	}
	else
	{
		// Get the previous pointer to the entry, delete the entry
		// set prevNodePtr -> next to nextNodePtr of the entry
		Node<ItemType>* prevNodePtr = getPrevPointerTo(anEntry);
		if (!prevNodePtr) return false;
		Node<ItemType>* entryPtr = prevNodePtr->getNext();
		nextNodePtr = entryPtr->getNext();
		prevNodePtr->setNext(nextNodePtr);
		delete entryPtr;
		entryPtr = nullptr;
		count--;
	}
	return true;
}

template <class ItemType>
void LinkedSet<ItemType>::clear()
{
	Node<ItemType>* currPtr = headPtr;
	while (currPtr)
	{
		Node<ItemType>* nextPtr = currPtr->getNext();
		delete currPtr;
		currPtr = nextPtr;
	}
	count = 0;
	headPtr = nullptr;
}

template <class ItemType>
bool LinkedSet<ItemType>::contains(const ItemType& anEntry) const
{
	return getPointerTo(anEntry) != nullptr;
}

template <class ItemType>
std::vector<ItemType> LinkedSet<ItemType>::toVector() const
{
	std::vector<ItemType> vec;
	vec.reserve(count);
	Node<ItemType>* currPtr = headPtr;
	while (currPtr)
	{
		vec.push_back(currPtr->getItem());
		currPtr = currPtr->getNext();
	}
	return vec;
}

template <class ItemType>
Node<ItemType>* LinkedSet<ItemType>::
getPrevPointerTo(const ItemType& target) const
{
	Node<ItemType>* currPtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;
	while (currPtr)
	{
		if (currPtr->getItem() == target)
			return prevPtr;
		prevPtr = currPtr;
		currPtr = currPtr->getNext();
	}
	return nullptr;
}

template <class ItemType>
Node<ItemType>* LinkedSet<ItemType>::getPointerTo(const ItemType& target) const
{
	// Check if the target is the first item
	if (headPtr && headPtr->getItem() == target)
		return headPtr;
	Node<ItemType>* prevPtr = getPrevPointerTo(target);
	return prevPtr ? prevPtr->getNext() : nullptr;
}