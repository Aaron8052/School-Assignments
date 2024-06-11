/*
	Name: Airport Info
	Copyright: 2024
	Author: Yu Jiang
	Date: 03/04/24 11:38
	Description: Compute statistics on
		airport traffic data
		
*/

#include <iostream>
using namespace std;

//Data definition
struct MonthlyAirTraffic {
	int landings;
	int departures;
};

// Prototypes
void getData(MonthlyAirTraffic*, int);
int getMaxLandings(MonthlyAirTraffic*, int);
double getAverageDepartures(MonthlyAirTraffic*, int);

// Main test driver
int main(int argc, char** argv) {
	const int NUM_MONTHS = 3;
	MonthlyAirTraffic traffic[NUM_MONTHS];
	getData(traffic, NUM_MONTHS);
	cout << "Max Landings: " << getMaxLandings(traffic, NUM_MONTHS);
	cout << "\nAverage Departures: " << getAverageDepartures(traffic, NUM_MONTHS);
	return 0;
}

// User input function
void getData(MonthlyAirTraffic* info, int size) {
	for(int i = 0 ; i < size; i++) {
		cout << "Enter landings for month #" << i + 1 << ": ";
		cin >> (*(info + i)).landings;
		cout << "Enter departures for month #" << i + 1 << ": ";
		cin >> (*(info + i)).departures;
	}
	cout << endl;
}

// Get Max Landings
int getMaxLandings(MonthlyAirTraffic* info, int size) {
	int max = 0;
	for (int i = 0 ; i < size; i++)
	{
		int landings = info[i].landings;
		if(landings > max)
			max = landings;
	}
	return max;
}

// Get Average Departures
double getAverageDepartures(MonthlyAirTraffic* info, int size) {
	int total = 0;
	for (int i = 0 ; i < size; i++)
	{
		total += info[i].departures;
	}
	return (double)total / size;
}