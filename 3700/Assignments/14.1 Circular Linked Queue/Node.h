/*
    Name: Node
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/18/2025
    Description: The C++ header file for the Node class.
*/

#ifndef NODE_H
#define NODE_H
#include <memory>

template <class T>
class Node
{
    private:
        T item;
        std::shared_ptr<Node<T>> next;

    public:
        Node();
        Node(const T& anItem);
        Node(const T& anItem, std::shared_ptr<Node<T>> nextNodePtr);
        void setItem(const T& anItem);
        void setNext(std::shared_ptr<Node<T>> nextNodePtr);
        T getItem() const;
        std::shared_ptr<Node<T>> getNext() const;
};

#include "Node.hpp"
#endif //NODE_H
