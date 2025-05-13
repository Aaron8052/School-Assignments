/*
    Name: ArrayStack.h
    Copyright: 2025
    Author: Yu Jiang
    Date: 4/13/25
    Description: The C++ header file for the ArrayStack.h class.
*/

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "StackInterface.h"

template <class ItemType>
class ArrayStack final : public StackInterface<ItemType>
{
	private:
		static const int DEFAULT_CAPACITY = 5;
		int capacity;
		ItemType* items = nullptr;
		int top;
		void expandCapacity();

	public:
		ArrayStack();
		ArrayStack(int);
		~ArrayStack() override;
		bool isEmpty() const override;
		bool push(const ItemType& newEntry) override;
		bool pop() override;
		ItemType peek() const override;
};

#include "ArrayStack.hpp"
#endif
