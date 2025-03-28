/*
    Name: Node Header
    Copyright: 2025
    Author: Yu Jiang
    Date: 03/28/2025
    Description: The C++ header file for the LinkedSet Node class.
*/

#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node
{
private:
    ItemType item;
    Node<ItemType> *next;
public:
    Node();
    Node(const ItemType &item);
    Node(const ItemType &item, Node<ItemType> *nextNodePtr);
    void setItem(const ItemType &item);
    void setNext(Node<ItemType> *nextNodePtr);
    ItemType getItem() const;
    Node<ItemType> *getNext() const;
};

//#include "Node.cpp"
#endif