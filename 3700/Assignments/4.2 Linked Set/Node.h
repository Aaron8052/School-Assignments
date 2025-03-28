/*
    Name: Node Header
    Copyright: 2025
    Author: Yu Jiang
    Date: 03/28/2025
    Description: The C++ header file for the LinkedSet Node class.
*/

#ifndef NODE_H
#define NODE_H

template <class ItemType>
class Node
{
	private:
		ItemType item;
		Node<ItemType>* next;

	public:
		Node();
		Node(const ItemType& anItem);
		Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
		void setItem(const ItemType& anItem);
		void setNext(Node<ItemType>* nextNodePtr);
		ItemType getItem() const;
		Node<ItemType>* getNext() const;
};

#include "Node.hpp"
#endif
