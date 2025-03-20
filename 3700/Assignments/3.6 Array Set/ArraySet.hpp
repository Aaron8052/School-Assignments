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
	if(count <= 0) return -1;
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
	if(maxCount <= 0) maxCount = DEFAULT_SIZE;
	else maxCount *= 2;
	ItemType* newArr = new ItemType[maxCount];
	for(int i = 0; i < count; i++)
		newArr[i] = containerArr[i];
	delete [] containerArr;
	containerArr = newArr;
}

template<class ItemType>
int ArraySet<ItemType>::getMaxSize() const
{
	return maxCount;
}

template<class ItemType>
int ArraySet<ItemType>::getCurrentSize() const
{
	return count;
}

template<class ItemType>
bool ArraySet<ItemType>::isEmpty() const
{
	return count <= 0;
}

template<class ItemType>
bool ArraySet<ItemType>::add(const ItemType& newEntry)
{
	if(indexOf(newEntry) > -1)
		return false;
	if(count >= maxCount)
		expandArray();
	containerArr[count++] = newEntry;
	return true;
}

template<class ItemType>
bool ArraySet<ItemType>::remove(const ItemType& anEntry)
{
	int index = indexOf(anEntry);
	if(index < 0)
		return false;
	if(count > 1 && index != count - 1)
		containerArr[index] = containerArr[count - 1];
	count--;
	return true;
}

template<class ItemType>
void ArraySet<ItemType>::clear()
{
	count = 0;
}

template<class ItemType>
bool ArraySet<ItemType>::contains(const ItemType& anEntry) const
{
	return indexOf(anEntry) > -1;
}

template<class ItemType>
std::vector<ItemType> ArraySet<ItemType>::toVector() const
{
	std::vector<ItemType> vec;
	vec.reserve(count);
	for(int i = 0; i < count; i++)
		vec.push_back(containerArr[i]);
	return vec;
}