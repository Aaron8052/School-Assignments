/*
	Name: ResizableArrayStackDriver.cpp
	Copyright: 2025
	Author: Yu Jiang
	Date: 4/13/25
	Description: The test driver for the ArrayStack class.
*/

#include <iostream>
#include "ArrayStack.h"
#include <stdexcept>
#include <cassert>

using namespace std;

bool popStackAll(ArrayStack<int>& stack)
{
	cout << "---- Stack ----" << endl;
	while (!stack.isEmpty())
	{
		try
		{
			cout << stack.peek() << " ";
		}
		catch (std::exception& ex)
		{
			cerr << ex.what() << endl;
			return false;
		}
		stack.pop();
	}
	cout << endl
		<< "---- End Stack ----"
		<< endl;
	return true;
}

bool testPush(ArrayStack<int>& stack)
{
	try
	{
		stack.push(5);
		stack.push(10);
		stack.push(-8);
		stack.push(0);
		stack.push(9);
		stack.push(-99);
		stack.push(-50);
		stack.push(100);
		return true;
	}
	catch (std::exception& ex)
	{
		cerr << ex.what() << endl;
		return false;
	}
}

int main()
{
	ArrayStack<int> stack;
	assert(testPush(stack));
	assert(popStackAll(stack));
	return 0;
}
