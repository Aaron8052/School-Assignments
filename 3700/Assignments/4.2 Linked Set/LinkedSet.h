/*
    Name: LinkedSet Header
    Copyright: 2025
    Author: Yu Jiang
    Date: 03/28/2025
    Description: The C++ header file for the LinkedSet class.
*/

#ifndef LINKED_SET
#define LINKED_SET

#include "SetInterface.h"

template<class ItemType>
class LinkedSet final: public SetInterface<ItemType>
{
private:
    int count = 0;

public:
    LinkedSet();
    ~LinkedSet() override;
    int getCurrentSize() const override;
    bool isEmpty() const override;
    bool add(const ItemType& newEntry) override;
    bool remove(const ItemType& anEntry) override;
    void clear() override;
    bool contains(const ItemType& anEntry) const override;
    std::vector<ItemType> toVector() const override;
};

#endif