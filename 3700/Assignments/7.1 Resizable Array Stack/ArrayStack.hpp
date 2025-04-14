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
	try
	{
		items = new ItemType[capacity];
	}
	catch (const bad_alloc& ex)
	{
		items = nullptr;
		throw MemoryAllocException("Failed to allocate the initial stack");
	}
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
void ArrayStack<ItemType>::expandCapacity()
{
	if (isEmpty()) return;
	int newSize = capacity * 2;
	ItemType* newArray = nullptr;
	try
	{
		newArray = new ItemType[newSize];
	}
	catch (const bad_alloc& ex)
	{
		throw MemoryAllocException("Failed to expand the stack");
	}

	capacity = newSize;
	for (int i = 0; i < top; i++)
		newArray[i] = items[i];
	delete [] items;
	items = newArray;
}

template <class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	if (top >= capacity)
		expandCapacity();
	top++;
	items[top] = newEntry;
	return true;
}

template <class ItemType>
bool ArrayStack<ItemType>::pop()
{
  	if(isEmpty()) return false;
	top--;
	return true;
}

template <class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
	assert(!isEmpty());
	return items[top];
}

#endif
