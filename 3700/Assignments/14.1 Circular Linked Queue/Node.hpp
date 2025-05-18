/*
    Name: Node
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/18/2025
    Description: The C++ implementation file for the Node class.
*/
#ifndef NODE_HPP
#define NODE_HPP

#include "Node.h"
template <class T>
Node<T>::Node() : next(nullptr)
{}

template <class T>
Node<T>::Node(const T& anItem)
    : item(anItem), next(nullptr)
{}

template <class T>
Node<T>::Node(const T& anItem, std::shared_ptr<Node<T>> nextNodePtr)
    : item(anItem), next(nextNodePtr)
{}

template <class T>
void Node<T>::setItem(const T& anItem)
{
    item = anItem;
}

template <class T>
void Node<T>::setNext(std::shared_ptr<Node<T>> nextNodePtr)
{
    next = nextNodePtr;
}

template <class T>
T Node<T>::getItem() const
{
    return item;
}

template <class T>
std::shared_ptr<Node<T>> Node<T>::getNext() const
{
    return next;
}
#endif // NODE_HPP
