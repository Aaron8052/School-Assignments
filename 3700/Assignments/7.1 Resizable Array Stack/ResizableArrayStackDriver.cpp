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

void popStackAll(ArrayStack<int>& stack)
{
	cout << "---- Stack ----" << endl;
	while (!stack.isEmpty())
	{
		cout << stack.peek() << " ";
		stack.pop();
	}
	cout << endl
		<< "---- End Stack ----"
		<< endl;
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
		popStackAll(stack);
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
	return 0;
}
