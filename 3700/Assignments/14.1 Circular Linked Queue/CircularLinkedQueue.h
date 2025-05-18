/*
    Name: CircularLinkedQueue
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/18/2025
    Description: The C++ header file
        for the CircularLinkedQueue class.
*/

#ifndef CIRCULARLINKEDQUEUE_H
#define CIRCULARLINKEDQUEUE_H

#include <memory>
#include "Node.h"
#include "QueueInterface.h"

template <class T>
class CircularLinkedQueue final : public QueueInterface<T>
{
	private:
		std::shared_ptr<Node<T>> tailPtr;

	public:
		bool isEmpty() const override;
		bool enqueue(const T& newEntry) override;
		bool dequeue() override;
		T peekFront() const override;
		CircularLinkedQueue();
		~CircularLinkedQueue() override;
};

#include "CircularLinkedQueue.hpp"
#endif //CIRCULARLINKEDQUEUE_H
