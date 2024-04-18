/*
	Name:
	Copyright:
	Author:
	Date: 11/03/24 11:46
	Description: This program demonstrates a Binary Search
*/


#include<iostream>
using namespace std;

int binarySearch(string [], int, string);

const int SIZE = 6;

int main() {
	int found; 
	string value;
	string array[] = {"Alice", "Bob", "Carol", "David", "Erin", "Frank"}; 

	cout << "Enter an string to search for:" << endl;
	cin >> value;

	found = binarySearch(array, SIZE, value);
	if (found == -1)
		cout << "The string " << value << " is not in the list" << endl;
	else {
		cout << "The string " << value << " is in position number "
		     << found + 1 << " of the list" << endl;
	}
	return 0;
}


//*******************************************************************
//                     binarySearch
//
// task:		  This searches an array for a particular value
// data in:       List of values in an orderd array, the number of
//                elements in the array, and the value searched for
//                in the array
// data returned: Position in the array of the value or -1 if value
//                not found
//
//*******************************************************************
int binarySearch(string array[], int numElems, string value) {
	int first = 0;
	int last = numElems - 1;
	int middle;

	while (first <= last) {
		middle = first + (last - first) / 2;

		if (array[middle] == value)
			return middle;

		else if (array[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}

	return -1;
}