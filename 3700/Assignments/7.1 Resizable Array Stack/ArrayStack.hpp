/*
    Name: ArrayStack
    Copyright: 2025
    Author: Yu Jiang
    Date: 4/13/25
    Description: The C++ implementation file for the ArrayStack class.
*/

#ifndef ARRAYSTACK
#define ARRAYSTACK
#include "ArrayStack.h"
#include "OutOfMemoryException.h"
#include "OutOfRangeException.h"

template <class ItemType>
ArrayStack<ItemType>::ArrayStack() : ArrayStack(DEFAULT_CAPACITY)
{}

template <class ItemType>
ArrayStack<ItemType>::ArrayStack(int initCapacity) :
	top(-1)
{
	if (initCapacity < 1)
		throw OutOfRangeException("Initial Capacity must be 1 or greater");
	try
	{
		items = new ItemType[capacity];
	}
	catch (const std::bad_alloc& ex)
	{
		items = nullptr;
		throw OutOfMemoryException("Failed to allocate the initial stack");
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
	catch (const std::bad_alloc& ex)
	{
		throw OutOfMemoryException(
			"Failed to expand the stack due to bad allocation");
	}
	capacity = newSize;
	for (int i = 0; i <= top; i++)
		newArray[i] = items[i];
	delete [] items;
	items = newArray;
}

template <class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	if (top >= capacity - 1)
		expandCapacity();
	top++;
	items[top] = newEntry;
	return true;
}

template <class ItemType>
bool ArrayStack<ItemType>::pop()
{
	if (isEmpty()) return false;
	top--;
	return true;
}

template <class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
	if (isEmpty())
		throw OutOfRangeException("Cannot peek empty stack");
	return items[top];
}

#endif
