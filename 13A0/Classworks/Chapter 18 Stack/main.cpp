/*
	Name: TestStack
	Copyright: 2024
	Author: Yu Jiang
	Date: 29/05/24 11:57
	Description: Test the static stack class.
*/

#include "Stack.h"
#include <iostream>
using namespace std;

// Report on empty and full stacks
template <class T>
void reportFull(Stack<T> &stack){
	cout << boolalpha;
	cout << "Is empty? " << stack.isEmpty() << endl;
	cout << "Is full? " << stack.isFull() << endl;
	cout << endl;
}

// Pop & print all data in a stack
template <class T>
void popAll(Stack<T> &stack){
	T popVal;
	while(!stack.isEmpty()){
		stack.pop(popVal);
		cout << "Poped value: " << popVal << endl;
	}
}

// Main test driver
int main(int argc, char** argv) {
	Stack<double> dblStack(20);
	cout << boolalpha;
	cout << "At start:\n";
	reportFull(dblStack);
	dblStack.push(10.4);
	dblStack.push(3.6);
	dblStack.push(5.45);
	dblStack.push(-2.1);
	dblStack.push(0);
	dblStack.push(42);
	cout << "\nAfter adding data:\n";
	reportFull(dblStack);
	
	// Test removing data
	popAll(dblStack);
	return 0;
}