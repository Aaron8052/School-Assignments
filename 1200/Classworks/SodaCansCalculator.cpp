/*
Yu Jiang
10/2/2023
This program calculates the cans needed of the amount of soda.
*/

#include <iostream>

using namespace std;


int main()
{
	int amount = 44;
	int cans = 0;
	
	cout << "Amount of soda: ";
	cin >> amount;
	
	float a = static_cast<float>(amount) / 12;
	cans += static_cast<int>(a);
	int r = a - cans + 0.99f;
	cans += r;
	
	
	cout << cans << " of cans are needed.\n";
	return 0;
}