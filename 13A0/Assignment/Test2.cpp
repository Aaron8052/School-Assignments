/*
	Name: Test #2 Program
	Copyright: 2024
	Author: Yu Jiang
	Date: 15/04/24 11:52
	Description: 
		Create a structure for weather data that includes fields 
		for monthly rainfall, low temperature, and high temperature. 
		Make an input function that takes an array of structures, 
		and prompts the user to fill in their information. 
		Make a processing function that takes the array 
		and returns the average rainfall. The main test driver 
		should create an array of 3 structures, send it to the 
		other functions, and print out the result of the latter function.
*/

#include <iostream>
using namespace std;

// Structure contains data of weather
struct WeatherData
{
	float monthlyRainFall = 0;
	int lowTemp = 0;
	int highTemp = 0;
};

// Prototypes
void getInput(WeatherData *data, int size);
float getAvgRainfall(WeatherData *data, int size);

// Main Driver
int main(int argc, char **argv)
{
	const int DATA_SIZE = 3;
	WeatherData data[DATA_SIZE];
	getInput(data, DATA_SIZE);
	cout << "\nAverage rainfall for " << DATA_SIZE << " months:\t"
		 << getAvgRainfall(data, DATA_SIZE);
	return 0;
}

// Get user input
void getInput(WeatherData *data, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "Rainfall Month #" << i << ": ";
		cin >> data[i].monthlyRainFall;
		cout << "Lowest Temperature Month #" << i << ": ";
		cin >> data[i].lowTemp;
		cout << "Highest Temperature Month #" << i << ": ";
		cin >> data[i].highTemp;
	}
	
}

// Get average Rainfall for months of size
float getAvgRainfall(WeatherData *data, int size)
{
	float totalRainfall = 0;
	for(int i = 0; i < size; i++)
	{
		totalRainfall += data[i].monthlyRainFall;
	}
	return totalRainfall / size;
}