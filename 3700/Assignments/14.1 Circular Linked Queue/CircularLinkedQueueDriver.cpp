/*
	Name: CircularLinkedQueue
	Copyright: 2025
	Author: Yu Jiang
	Date: 05/18/2025
	Description: The C++ test driver
		for the CircularLinkedQueue class.
*/

#include <iostream>
#include "QueueInterface.h"
#include "CircularLinkedQueue.h"

std::string strFromBool(const bool& b)
{
	return b ? "YES" : "NO";
}

void dequeueAll(QueueInterface<int>& queue)
{
	std::cout
		<< "[Queue]" << std::endl
		<< "Is Empty: "
		<< strFromBool(queue.isEmpty())
		<< std::endl;
	while (!queue.isEmpty())
	{
		std::cout << queue.peekFront()
			<< " ";
		queue.dequeue();
	}
	std::cout << std::endl
		<< std::endl;
}

int main()
{
	CircularLinkedQueue<int> queue;
	dequeueAll(queue);
	for (int i = -10; i < 10; i++)
		queue.enqueue(i);
	dequeueAll(queue);
	dequeueAll(queue);
	return 0;
}
