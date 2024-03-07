/*
Yu Jiang
Assignment 7.1
FindArrayMinMax.cpp
3/6/2024
This program gets the largest and smallest numbers in user inputs;
*/

#include <iostream>
using namespace std;

// Headers
float GetLargetNumInArray(float array[], int size); 
float GetSmallestNumInArray(float array[], int size); 

void OutputLargestNumber(float num);
void OutputSmallestNumber(float num);

const int MAXNUMBERS = 10;
int main()
{
	// Initialize the user inputs array
	float userInputs[MAXNUMBERS] = {0};
	
	// Prompt user for inputs
	cout << "Please enter 10 numbers, press \"enter\" OR \"space\" after each number input\n";
	
	
	for(int i = 0 ; i < MAXNUMBERS; )
	{
		// check if user entered a valid number
		if(cin >> userInputs[i])
		{
			i ++;
			continue;
		}
		
		cout << "Please enter a valid number!\n";
		cin.clear();
		cin.ignore();
	}
	
	cout << endl;
	
	// get largest & smallest numbers
	float largestNum = GetLargetNumInArray(userInputs, MAXNUMBERS);
	float smallestNum = GetSmallestNumInArray(userInputs, MAXNUMBERS);
	
	// output the results
	OutputLargestNumber(largestNum);
	OutputSmallestNumber(smallestNum);
}

// function that finds largest number in an array
float GetLargetNumInArray(float array[], int size)
{
	float largest = array[0];
	
	for(int i = 0; i < size; i++)
	{
		float current = array[i];
		
		if(current <= largest)
			continue;
			
		largest = current;
	}
	
	return largest;
}

// function that finds smallest number in an array
float GetSmallestNumInArray(float array[], int size)
{
	float smallest = array[0];
	
	for(int i = 0; i < size; i++)
	{
		float current = array[i];
		
		if(current >= smallest)
			continue;
			
		smallest = current;
	}
	
	return smallest;
}


// functions that output the results
void OutputLargestNumber(float num)
{
	cout << "The largest number is: " << num << endl;
}

void OutputSmallestNumber(float num)
{
	cout << "The smallest number is: " << num << endl;
}