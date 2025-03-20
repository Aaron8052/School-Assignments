/*
	Name: ArraySet
	Copyright: 2025
	Author: Yu Jiang
	Date: 18/03/25 20:58
	Description: An array set header.
*/

#ifndef ARRAY_SET
#define ARRAY_SET

#include "SetInterface.h"

template<class ItemType>
class ArraySet final: public SetInterface<ItemType>
{
	private:
		static const int DEFAULT_SIZE = 16;
		int maxCount = -1;
		int count = -1;
		ItemType* containerArr = nullptr;
		int indexOf(const ItemType& anEntry) const;
		
	public:
		ArraySet();
		ArraySet(int);
		~ArraySet(){
			if(containerArr)
			delete [] containerArr;
			containerArr = nullptr;
		}
		int getCurrentSize() const override;
		bool isEmpty() const override;
		bool add(const ItemType& newEntry) override;
		bool remove(const ItemType& anEntry) override;
		void clear() override;
		bool contains(const ItemType& anEntry) const override;
		std::vector<ItemType> toVector() const override;
};

#include "ArraySet.cpp"
#endif