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
ArrayStack<ItemType>::ArrayStack() : ArrayStack(DEFAULT_CAPACITY)
{}

template <class ItemType>
ArrayStack<ItemType>::ArrayStack(const int capacity) :
	top(-1), capacity(capacity)
{
	items = new ItemType[capacity];
}

template <class ItemType>
ArrayStack<ItemType>::~ArrayStack()
{
	delete [] items;
	items = nullptr;
}

template <class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;
}

template <class ItemType>
bool ArrayStack<ItemType>::expandCapacity()
{
	if (isEmpty()) return;
	int newSize = capacity * 2;
	ItemType* newArray = nullptr;
	try
	{
		newArray = new ItemType[newSize];
	}
	catch (std::exception& ex)
	{
		throw MemoryAllocException("Failed to expand the stack\n");
		return false;
	}

	capacity = newSize;
	for (int i = 0; i < top; i++)
		newArray[i] = items[i];
	delete [] items;
	items = newArray;
	return true;
}

template <class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	if (top >= capacity)
		expandCapacity();
	top++;
	items[top] = newEntry;
}

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
