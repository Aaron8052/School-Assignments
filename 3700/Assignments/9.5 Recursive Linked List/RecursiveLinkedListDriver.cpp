/*
    Name: RecursiveLinkedListDriver
    Copyright: 2025
    Author: Yu Jiang
    Date: 4/24/25
    Description: The C++ test driver for the RecursiveLinkedListDriver class.
*/

#include <iostream>
#include "ListInterface.h"
#include "LinkedList.h"
#include <cassert>

void printList(ListInterface<int> &list)
{
	std::cout << "---- Print List ----" << std::endl;
	int length = list.getLength();
	std::cout << "Length: " << length << std::endl;
	if (list.isEmpty())
	{
		std::cout << "List is empty." << std::endl;
		return;
	}
	for (int i = 1; i <= length; i++)
	{
		std::cout << list.getEntry(i) << std::endl;
	}
}

void testGetEntry(LinkedList<int> &list, int position)
{
	int entry = list.getEntry(position);
	std::cout << "Entry at position " << position << ": " << entry << std::endl;
}

void testInsert(LinkedList<int> &list)
{
	std::cout << "---- Insert ----" << std::endl;
	assert(list.insert(1, 5));
	assert(list.insert(2, 34));
	assert(list.insert(1, -432));
	assert(list.insert(4, 55));
	assert(list.insert(1, 0));
}

void testRemove(LinkedList<int> &list)
{
	std::cout << "---- Remove ----" << std::endl;
	assert(list.remove(2));
	assert(list.remove(1));
	assert(list.remove(2));
	assert(list.remove(2));
	assert(list.remove(1));
}

void replace(LinkedList<int> &list, int position, int newEntry)
{
	std::cout << "Replace position " << position << ": " << list.getEntry(position)
		<< " to: " << newEntry << std::endl;
	list.replace(position, newEntry);
}

void testReplace(LinkedList<int> &list)
{
	std::cout << "---- Replace ----" << std::endl;
	replace(list, 1, 50);
	replace(list, 5, -7854);
	replace(list, 2, -999);
}

int main()
{
	LinkedList<int> list;
	testInsert(list);
	printList(list);
	testGetEntry(list, 3);
	testGetEntry(list, 1);
	testReplace(list);
	printList(list);
	testRemove(list);
	printList(list);
	testInsert(list);
	printList(list);
	list.clear();
	printList(list);
	return 0;
}
