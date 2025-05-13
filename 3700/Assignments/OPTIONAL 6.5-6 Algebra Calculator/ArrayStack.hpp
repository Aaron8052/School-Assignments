/*
    Name: ArrayStack
    Copyright: 2025
    Author: Yu Jiang
    Date: 4/13/25
    Description: The C++ implementation file for the ArrayStack class.
*/

#ifndef ARRAYSTACK
#define ARRAYSTACK
#include <assert.h>

#include "ArrayStack.h"

template <class ItemType>
ArrayStack<ItemType>::ArrayStack() : ArrayStack(DEFAULT_CAPACITY)
{}

template <class ItemType>
ArrayStack<ItemType>::ArrayStack(int initCapacity) :
	top(-1), capacity(initCapacity)
{
	if (initCapacity < 1)
		return;
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
void ArrayStack<ItemType>::expandCapacity()
{
	if (isEmpty()) return;
	int newSize = capacity * 2;
	ItemType* newArray = nullptr;
	newArray = new ItemType[newSize];
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
	assert(!isEmpty());
	return items[top];
}

#endif
