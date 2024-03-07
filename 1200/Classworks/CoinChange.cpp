/*
Yu Jiang
This program find coin denomination for 
user entered change.
*/

#include <iostream>

using namespace std;

const int QUARTER_VALUE = 25;
const int DIME_VALUE = 10;
const int NICKEL_VALUE = 5;

int main(){
	
	int change = 0;
	
	//Prompt the user to enter some change upto 99 cents
	cout << "Enter the change that you convert to coins: ";
		 
	cin >> change;
	
	int temp = change;
	
	int quarters = temp / QUARTER_VALUE;
	temp %= QUARTER_VALUE;
	
	int dimes = temp / DIME_VALUE;
	temp %= DIME_VALUE;
	
	int nickels = temp / NICKEL_VALUE;
	temp %= NICKEL_VALUE;
	
	
	printf("%i cents has %i quarters, %i dimes, %i nickels, %i pennies\n\n", 
		change, 
		quarters, 
		dimes, 
		nickels, 
		temp);
	
	
	system("pause");
	
	return 0;
}