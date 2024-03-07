/*
Yu Jiang
10/2/2023
This program calculates between the two num of minutes
*/

#include <iostream>

using namespace std;

int main()
{
	int firstTime = 0;
	int secTime = 0;
	
	cout << "First Time (Minutes): ";
	cin >> firstTime;
	
	cout << "\nSecond Time (Minutes): ";
	cin >> secTime;
	
	int timeGap = secTime > firstTime ? (secTime - firstTime) : (firstTime - secTime);
	
	
	int hrs = timeGap / 60;
	int mins = timeGap % 60;
	
	printf("\n%i hours %i minutes\n", hrs, mins);
	
	system("pause");
}