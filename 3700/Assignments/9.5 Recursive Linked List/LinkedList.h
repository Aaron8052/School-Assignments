/*
	Name: Linked List
	Copyright: 2025
	Author: Yu Jiang
	Date: 4/24/25
	Description: The C++ header for the LinkedList class.
*/

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class LinkedList : public ListInterface<ItemType>
{
	private:
		Node<ItemType>* headPtr;
		int itemCount;

		// Locates a specified node in this linked list.
		// @pre  position is the number of the desired node;
		//       position >= 1 and position <= itemCount.
		// @post  The node is found and a pointer to it is returned.
		// @param position  The number of the node to locate.
		// @return  A pointer to the node at the given position.
		Node<ItemType>* getNodeAt(int position) const;
		Node<ItemType>* getNodeAtRecur(Node<ItemType>* currNode, int position) const;
		Node<ItemType>* removeRecur(Node<ItemType>* currNode,
									Node<ItemType>* subChainPtr, int position);
		void clearChain(Node<ItemType>* currNode);
		Node<ItemType>* insertChain(int position,
									Node<ItemType>* newNode, Node<ItemType>* subChainPtr);

	public:
		LinkedList();
		LinkedList(const LinkedList<ItemType> &aList);
		virtual ~LinkedList();

		bool isEmpty() const override;
		int getLength() const override;
		bool insert(int newPosition, const ItemType &newEntry) override;
		bool remove(int position) override;
		void clear() override;

		/** @throw PrecondViolatedExcep if position < 1 or
		                                   position > getLength(). */
		ItemType getEntry(int position) const override;

		/** @throw PrecondViolatedExcep if position < 1 or
		                                   position > getLength(). */
		void replace(int position, const ItemType &newEntry) override;
}; // end LinkedList

#include "LinkedList.hpp"
#endif
