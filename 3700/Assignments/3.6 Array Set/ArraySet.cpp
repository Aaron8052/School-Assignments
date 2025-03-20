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
	: ArraySet::maxCount(initSize),
	ArraySet::containerArr(new ItemType[initSize])
{}
