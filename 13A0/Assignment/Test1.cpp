// Make a function that accepts an integer array and the array's size as arguments. 
// The function should create a new array that is one element larger than the argument array, 
// containing the value zero (0) for the first element, followed by a copy of all the elements in the original array. 
// Then it returns a pointer to the new array. The main test driver should initialize an array (no user input), send it to the other function, and print the result.

/*
	Name: Test 1
	Copyright: 2024
	Author: Yu Jiang
	Date: 25/03/24 11:49
	Description: 
		The program inserts a zero
		in front of a custom array.
*/

#include <iostream>
using namespace std;

// insert a zero in the first element of an array
int* insertZeroToArray(int* arr, int &size)
{
	size++;
	int* newArray = new int[size];
	// Assign 0 to the 1st element of array
	*(newArray) = 0;
	for(int i = 0; i < size; i++)
	{
		*(newArray + i + 1) = *(arr + i);
	}
	return newArray;
}

// prints the array
void printArray(int* arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "#" << i + 1 << ":\t" << *(arr + i) << endl;
	}
}

//main func
int main()
{
	int size = 6;
	int array[] = {10, 20, 30, 40, 50, 60};
	cout << "===Original Array===\n";
	printArray(array, size);
	int* newArray = insertZeroToArray(array, size);
	cout << "===New Array===\n";
	printArray(newArray, size);
	delete [] newArray;
	return 0;
}