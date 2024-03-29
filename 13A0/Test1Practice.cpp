/*
	Name: Test 1 Practice
	Copyright: 2024
	Author: Yu Jiang
	Date: 24/03/24 14:08
	Description: 
		Make a function that accepts an integer array and the array's size as arguments. 
		The function should create a new array that is twice the size of the argument array. 
		The function should copy the contents of the argument array to the new array 
		and initialize the unused elements of the second array with 0. 
		Then it returns a pointer to the new array. 
		The main test driver should initialize an array (no user input), 
		send it to the other function, and print the result.
*/

#include <iostream>
using namespace std;

// print array
void printArray(int* arr, int size)
{
	for(int i = 0; i < size; i ++)
	{
		cout << "Element #" << i + 1 << ": " << *(arr + i) << endl;
	}
}

// create a new array that is twice the size of the argument array. 
// copy the contents of the argument array to the new array 
int* doubleArraySize(int* arr, int size)
{
	int newSize = size * 2;
	int* array = new int[newSize];
	for(int i = 0; i < newSize; i ++)
	{
		*(array + i) = (i < size) ? *(arr + i) : 0;
	}
	return array;
}

// main func
int main()
{
	const int SIZE = 10;
	int array[] = {114514, 1919810, 55555, 23333, 123456, 987456, 4516, 4789, 5456, 1231};
	int* newArray = doubleArraySize(array, SIZE);
	printArray(newArray, SIZE * 2);
	delete [] newArray;
	system("pause");
}