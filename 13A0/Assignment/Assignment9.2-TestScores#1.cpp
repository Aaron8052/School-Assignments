/*
	Name: Test Scores #1
	Copyright: 2024
	Author: Yu Jiang
	Date: 23/03/24 21:54
	Description: 
		Book Chapter 9 Programming Challenges #2
		A program that dynamically allocates an array
		large enough to hold user-defined number. 
		And then sort numbers in ascending order.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

// this func rounds decimal places to "precision"
float roundDecimal(float decimal, int precision)
{
	int position = pow(10, precision);
	return round(decimal * position) / position;
} 

// this func rounds decimal places to two
float roundDecimal(float decimal)
{
	return roundDecimal(decimal, 2);
}

// get average of an array
float getArrayAverage(float* array, int size)
{
	float sum;
	for(int i = 0; i < size; i++)
	{
		sum += roundDecimal(*(array + i));
	}
	return roundDecimal(sum / size);
}

// print all size elements in array
void printScores(float* array, int size)
{
	cout << "========Scores========" << endl
		 << fixed << setprecision(2);
	for(int i = 0; i < size; i++)
	{
		cout << "Score #" << i + 1 << ":\t" 
			 << setw(6) << roundDecimal(*(array + i)) << endl;
	}
	cout << "Average:\t" 
		 << setw(6) << getArrayAverage(array, size) 
		 << endl;
}

// find the smallest element of an array
int getMinElementInArray(float* array, int begin, int count)
{
	// index of smallest string
	int smallest = begin;
	
	// the initial smallest string is already set to "begin",
	// so we start with the next element by + 1
	for(int i = begin + 1; i < count; i++)
	{
		// compare the current string with known smallest string
		if(*(array + i) < *(array + smallest))
			smallest = i;
	}
	return smallest;
}

// sort an array using selection sort in ascending order
void selectionSortArray(float* array, int size)
{
	for(int i = 0; i < size; i++)
	{
		int smallest = getMinElementInArray(array, i, size);
		
		// skip if the current element is already in correct position
		if(smallest == i)
			continue;
			
		// swap element i with smallest element
		float temp = *(array + i);
		*(array + i) = *(array + smallest);
		*(array + smallest) = temp;
	}
}

// Prompt user to enter number of scores
// and validate for input
int promptUserForNumOfScores()
{
	int arraySize = 0;
	cout << "Please enter number of test scores: ";
	cin >> arraySize;
	while(arraySize <= 0)
	{
		cout << "Number of test scores can not be 0 or less than 0!"
			 << "\nPlease enter number of test scores: ";
		cin >> arraySize;
	}
	return arraySize;
}

// Prompt user to enter scores
// and validate for input
void promptUserForScoresInput(float* array, int size)
{
	if(size <= 0)
		return;
	for(int i = 0; i < size; )
	{
		cout << "Please enter score #" << i + 1 << ": ";	
		cin >> 	*(array + i);
		if(*(array + i) < 0)
		{
			cout << "Score can not be less than 0!\n";
			continue;
		}
		i++;
	}
}

// main function
int main()
{
	int arraySize = promptUserForNumOfScores();
	float* scores = new float[arraySize];
	promptUserForScoresInput(scores, arraySize);
	selectionSortArray(scores, arraySize);
	printScores(scores, arraySize);
	system("pause");
	delete [] scores;
}