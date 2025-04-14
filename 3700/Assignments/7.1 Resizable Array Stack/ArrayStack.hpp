/*
    Name: ArrayStack
    Copyright: 2025
    Author: Yu Jiang
    Date: 4/13/25
    Description: The C++ implementation file for the ArrayStack class.
*/

#ifndef ARRAYSTACK
#define ARRAYSTACK

#include <cassert>
#include "ArrayStack.h"

template <class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{}

template <class ItemType>
ArrayStack<ItemType>::~ArrayStack() {}

template <class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;
} // end isEmpty

template <class ItemType>
void ArrayStack<ItemType>::expandCapacity()
{}

template <class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	bool result = false;
	if (top < MAX_STACK - 1)
	{
		// Does stack have room for newEntry?
		top++;
		items[top] = newEntry;
		result = true;
	} // end if
	return result;
} // end push

template <class ItemType>
bool ArrayStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
		top--;
		result = true;
	} // end if
	return result;
} // end pop

template <class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
	assert(!isEmpty()); // Enforce precondition
	// Stack is not empty; return top
	return items[top];
} // end peek

#endif
