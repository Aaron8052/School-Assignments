/*
	Name: ArraySet
	Copyright: 2025
	Author: Yu Jiang
	Date: 18/03/25 21:37
	Description: An array set implementation
*/

#include "ArraySet.h"

template<class ItemType>
ArraySet<ItemType>::ArraySet() 
	: ArraySet<ItemType>(ArraySet::DEFAULT_SIZE)
{}

template<class ItemType>
ArraySet<ItemType>::ArraySet(int initSize) 
	: maxCount(initSize),
	  containerArr(new ItemType[initSize])
{}

template<class ItemType>
ArraySet<ItemType>::~ArraySet() 
{
	if(containerArr)
		delete [] containerArr;
	containerArr = nullptr;
}

template<class ItemType>
int ArraySet<ItemType>::indexOf(const ItemType& anEntry) const
{
	if(count <= 0)
		return -1;
	for(int i = 0; i < count; i++)
	{
		if(containerArr[i] == anEntry)
			return i;
	}
	return -1;
}
	
template<class ItemType>
void ArraySet<ItemType>::expandArray()
{
	if(maxCount <= 0)
		return;
	maxCount *= 2;
	ItemType* newArr = new ItemType[maxCount];
	for(int i = 0; i < count; i++)
	{
		newArr[i] = containerArr[i];
	}
	delete [] containerArr;
	containerArr = newArr;
}