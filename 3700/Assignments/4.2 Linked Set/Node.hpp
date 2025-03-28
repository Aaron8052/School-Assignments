/*
    Name: Node Implementations
    Copyright: 2025
    Author: Yu Jiang
    Date: 03/28/2025
    Description: The C++ Implementations file for the LinkedSet Node class.
*/

//#include "Node.h"

template <class ItemType>
Node<ItemType>::Node() : next(nullptr)
{}

template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem)
	: item(anItem), next(nullptr)
{}

template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr)
	: item(anItem), next(nextNodePtr)
{}

template <class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}

template <class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

template <class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}
