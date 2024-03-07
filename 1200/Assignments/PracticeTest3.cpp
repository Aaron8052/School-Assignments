#include <iostream>
using namespace std;


const int ROWS = 5;
const int COLS = 4;


double getAverage(double arr[][COLS])
{
	double sum = 0;
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
	}
	
	return sum / (ROWS * COLS);
}



int main()
{
	
	double arr[ROWS][COLS] = 
	{
		{50,2,3,4},
		{1,2,3,4},
		{1,2,3,4},
		{1,45,3,4},
		{1,2,30,4}
	};
	
	cout << "Average: " << getAverage(arr);
}