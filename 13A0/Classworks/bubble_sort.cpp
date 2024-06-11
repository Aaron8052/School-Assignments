// This program uses a bubble sort to arrange an array of integers in
// ascending order

#include<iostream>
using namespace std;

// YU JIANG

// function prototypes

void bubbleSortArray(int [], int);
void displayArray(int[], int);

const int SIZE = 5;

int main() {
	int values[SIZE] = {76,77,70,24,9};

	cout << "The values before the bubble sort is performed are:" << endl;
	displayArray(values,SIZE);

	bubbleSortArray(values,SIZE);

	cout << "The values after the bubble sort is performed are:" << endl;
	displayArray(values,SIZE);

	return 0;
}
//******************************************************************
//                      displayArray
//
// task:		to print the array
// data in:       the array to be printed, the array size
// data out:      none
//
//******************************************************************

void displayArray(int array[], int elems) {  // function heading
	// displays the array
	for (int count = 0; count < elems; count++)
		cout << array[count] << "  ";
	cout << endl;
}

//******************************************************************
//                      bubbleSortArray
//
// task:		to sort values of an array in ascending order
// data in:       the array, the array size
// data out:      the sorted array
//
//******************************************************************


void bubbleSortArray(int array[], int elems) {
	bool swap;
	int temp;
	int bottom = elems - 1;
	do {
		swap = false;
		for (int count = 0; count < bottom; count++) {
			if (array[count] > array[count+1]) {
				temp = array[count];
				array[count] = array[count+1];
				array[count+1] = temp;
				swap = true;
			}
		}
		displayArray(array, elems);
		bottom--;
	} while(swap != false);
}
