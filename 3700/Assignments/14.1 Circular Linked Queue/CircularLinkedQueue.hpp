/*
    Name: CircularLinkedQueue
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/18/2025
    Description: The C++ implementation file
		for the CircularLinkedQueue class.
*/

#ifndef CIRCULARLINKEDQUEUE_HPP
#define CIRCULARLINKEDQUEUE_HPP
#include "CircularLinkedQueue.h"
#include "PrecondViolationException.h"

template <class T>
CircularLinkedQueue<T>::CircularLinkedQueue()
{}

template <class T>
CircularLinkedQueue<T>::~CircularLinkedQueue()
{
	if (isEmpty()) return;
	tailPtr->setNext(nullptr);
	tailPtr = nullptr;
}

template <class T>
bool CircularLinkedQueue<T>::isEmpty() const
{
	return !tailPtr;
}

template <class T>
bool CircularLinkedQueue<T>::enqueue(const T& newEntry)
{
	if (isEmpty())
	{
		std::shared_ptr<Node<T>> newTailPtr(new Node<T>(newEntry));
		newTailPtr->setNext(newTailPtr);
		tailPtr = newTailPtr;
		return true;
	}
	auto headPtr = tailPtr->getNext();
	std::shared_ptr<Node<T>> newTailPtr(new Node<T>(newEntry, headPtr));
	tailPtr->setNext(newTailPtr);
	tailPtr = newTailPtr;
	return true;
}

template <class T>
bool CircularLinkedQueue<T>::dequeue()
{
	if (isEmpty())
		return false;
	auto headPtr = tailPtr->getNext();
	if (headPtr == tailPtr)
	{
		headPtr->setNext(nullptr);
		tailPtr->setNext(nullptr);
		tailPtr = nullptr;
	}
	else
	{
		auto nextPtr = headPtr->getNext();
		headPtr->setNext(nullptr);
		tailPtr->setNext(nextPtr);
	}
	return true;
}

template <class T>
T CircularLinkedQueue<T>::peekFront() const
{
	if (isEmpty())
		throw PrecondViolationException("Queue is empty.");
	return tailPtr->getNext()->getItem();
}

#endif
