/*
	Name: FindArrayMinMax
	Copyright: 2024
	Author: Yu Jiang
	Date: 03/06/24 08:58PM
	Description: This program gets the largest and smallest numbers in user inputs.
*/

#include <iostream>
#include <iomanip>
using namespace std;
#define FORMAT_OUTPUT(output) setw(10) << (output) << endl

// Headers
void promptUserInput(float* array, int size);
float getLargetNumInArray(float* array, int size); 
float getSmallestNumInArray(float* array, int size); 
void outputLargestNumber(float num);
void outputSmallestNumber(float num);

// the main function
int main()
{
	const int MAXNUMBERS = 10;
	
	// Initialize the user inputs array
	float userInputs[MAXNUMBERS] = {0};
	
	// Prompt user for inputs
	cout << "Please enter 10 numbers, "
		 <<	"press \"enter\" OR \"space\" after each number input\n";
	promptUserInput(userInputs, MAXNUMBERS);
	cout << endl;
	
	// get largest & smallest numbers
	float largestNum = getLargetNumInArray(userInputs, MAXNUMBERS);
	float smallestNum = getSmallestNumInArray(userInputs, MAXNUMBERS);
	
	// output the results
	outputLargestNumber(largestNum);
	outputSmallestNumber(smallestNum);
}

// this function prompts user for inputs
void promptUserInput(float* userInputs, int size)
{
	for (int i = 0; i < size; )
	{
		// check if user entered a valid number
		if(cin >> userInputs[i])
		{
			i ++;
			continue;
		}
		
		// invalid user input
		cout << "Please enter a valid number!\n";
		cin.clear();
		cin.ignore();
	}
	cout << endl;
}

// function that finds largest number in an array
float getLargetNumInArray(float* array, int size)
{
	float largest = array[0];
	for(int i = 0; i < size; i++)
	{
		float current = array[i];
		
		// compare the numbers to see which one is bigger
		if(current <= largest)
			continue;
		largest = current;
	}
	return largest;
}

// function that finds smallest number in an array
float getSmallestNumInArray(float* array, int size)
{
	float smallest = array[0];
	for(int i = 0; i < size; i++)
	{
		float current = array[i];
		
		// compare the numbers to see which one is smaller
		if(current >= smallest)
			continue;
		smallest = current;
	}
	return smallest;
}

// function that output the largest result
void outputLargestNumber(float num)
{
	cout << "The largest number is:\t" 
		 << FORMAT_OUTPUT(num);
}

// function that output the smallest result
void outputSmallestNumber(float num)
{
	cout << "The smallest number is:\t" 
		 << FORMAT_OUTPUT(num);
}
