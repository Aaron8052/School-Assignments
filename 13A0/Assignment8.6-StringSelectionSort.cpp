/*
	Name: String Selection Sort
	Copyright: Yu Jiang
	Author: Yu Jiang
	Date: 17/03/24 11:25
	Description: 
		Sort a string array using selection sort 
		by alphbetical order
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// print all size elements in array
void printArray(string* array, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "#" << i + 1 << ":\t"<< array[i] << endl;
	}
}

// find the smallest string by ABC order, returns its index
int getMinStringInArray(string* array, int begin, int count)
{
	// index of smallest string
	int smallest = begin;
	
	// the initial smallest string is already set to "begin",
	// so we start with the next element by + 1
	for(int i = begin + 1; i < count; i++)
	{
		// compare the current string with known smallest string
		if(array[i] < array[smallest])
			smallest = i;
	}
	return smallest;
}

// sort a string array using selection sort by alphbetical order
void selectionSortArray(string* array, int size)
{
	for(int i = 0; i < size; i++)
	{
		int smallest = getMinStringInArray(array, i, size);
		
		// skip if the current element is already in correct position
		if(smallest == i)
			continue;
			
		// swap element i with smallest element
		string temp = array[i];
		array[i] = array[smallest];
		array[smallest] = temp;
	}
}

// main function
int main()
{
	const int NUM_NAMES = 20;
	string names[NUM_NAMES] =
	{
		"Collins, Bill", "Smith, Bart", "Allen, Jim",
		"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
		"Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
		"Looney, Joe", "Wolfe, Bill", "James, Jean",
		"Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
		"Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
		"Pike, Gordon", "Holland, Beth"
	};
	cout << "Initial Array" << endl;
	printArray(names, NUM_NAMES);
	selectionSortArray(names, NUM_NAMES);
	cout << "\nSorted Array" << endl;
	printArray(names, NUM_NAMES);
	return 0;
}
