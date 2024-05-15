/*
	Name: Test SimpleVector
	Copyright: 2024
	Author: Yu Jiang
	Date: 15/05/24 12:01
	Description: Test the SimpleVector class.
*/

#include <iostream>
#include "SimpleVector.h"
#include "FeetInches.h"
using namespace std;

// Main test driver
int main(int argc, char** argv) {
	
	// Test a vector of int
	SimpleVector<int> vecInt(3);
	vecInt[0] = 5;
	vecInt[1] = 9;
	vecInt[2] = -4;
	cout << "Data in the vector: ";
	for(int i = 0; i < vecInt.size(); i ++){
		cout << vecInt.getElementAt(i) << " ";
	}
	cout << endl;
	
	// Test a vector of FeetInches
	SimpleVector<FeetInches> vecFeet(3);
	vecFeet[0] = FeetInches(2, 5);
	vecFeet[1] = FeetInches(6, 1);
	vecFeet[2] = FeetInches(5, 11);
	cout << "Data in the FeetInches vector: \n";
	for(int i = 0; i < vecFeet.size(); i ++){
		FeetInches element = vecFeet.getElementAt(i);
		
		cout << element << endl;
	}
	cout << endl;
	return 0;
}