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

void printList(ListInterface<int>& list)
{
    std::cout << "---- List ----";
    for (int i = 0; i < list.getLength(); i++)
    {
        std::cout << list.getEntry(i) << std::endl;
    }
}

int main()
{
    LinkedList<int> list;

}