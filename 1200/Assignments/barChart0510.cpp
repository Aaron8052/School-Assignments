/*
Yu Jiang
11/23/2023
*/

#include <iostream>
#include <cmath>
using namespace std;


float PromtUserForSales(int index);

string GetOutputStringForSales(int index, float sales);

const int AMOUNT_PER_STAR = 100;


int main()
{
	float store1Sales = PromtUserForSales(1);
	float store2Sales = PromtUserForSales(2);
	float store3Sales = PromtUserForSales(3);
	float store4Sales = PromtUserForSales(4);
	float store5Sales = PromtUserForSales(5);
	
	cout << "\n=================================\n"
		 << "SALES BAR CHART\n(Each * = $100)\n"
		 << GetOutputStringForSales(1, store1Sales) << endl
		 << GetOutputStringForSales(2, store2Sales) << endl
		 << GetOutputStringForSales(3, store3Sales) << endl
		 << GetOutputStringForSales(4, store4Sales) << endl
		 << GetOutputStringForSales(5, store5Sales) << endl;
	return 0;
}



float PromtUserForSales(int index)
{
	float userInput = -1;
	
	while (cin.fail() || userInput < 0)
	{
		cin.clear();
		
		cout << "Enter today's sales for store " << index <<": ";
		
		cin >> userInput;
	}
	return userInput;
}

string GetOutputStringForSales(int index, float sales)
{
	int salesInt = floor(sales / AMOUNT_PER_STAR);
	string output = "Store " + to_string(index) + ": ";
	
	
	for(int i = 0; i < salesInt; ++i)
	{
		output += "*";
	}
	return output;
}