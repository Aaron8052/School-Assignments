/*
	Name: ID Search
	Copyright: 2024
	Author: Yu Jiang
	Date: 20/03/24 11:42
	Description: 
		This program read in ID numbers and save them into an array.
		And then search for a perdicular ID.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
int* getIDs(int);
int searchIDs(int*, int, int);

// Main driver
int main()
{
	int size, target, found;
	int* arrayPtr = nullptr;
	cout << "How many IDs do you have? ";
	cin >> size;
	arrayPtr = getIDs(size);
	cout << "What ID do you want to find? ";
	cin >> target;
	found = searchIDs(arrayPtr, size, target);
	cout << (found == -1 ? "Search ID not found" : "Search ID was found.") << endl;
	return 0;
}

// Get the array of IDs
int* getIDs(int numberOfIDs)
{
	int *arrayLoc = new int[numberOfIDs];
	for(int i = 0; i < numberOfIDs; i++)
	{
		cout << "Enter ID #" << i + 1 << ": ";
		cin >> *(arrayLoc + i);
	}
	return arrayLoc;
}

// Search an array of IDs
int searchIDs(int* idArray, int size, int id)
{
	for(int i = 0; i < size; i++)
	{
		if(idArray[i] == id)
			return i;
	}
	return -1;
}