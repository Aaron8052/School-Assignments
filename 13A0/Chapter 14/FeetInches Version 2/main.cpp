/*
	Name: FeetInchesTest
	Copyright: 2024
	Author: Yu Jiang
	Date: 08/05/24 12:11
	Description: Test the FeetInches Class
*/
#include <iostream>
#include "FeetInches.h"
using namespace std;

// Rporting Function
void printMeasure(const FeetInches &measure){
	cout << "Measure is: " << measure.getFeet()
		<< " Feet " << measure.getInches() << " Inches\n";
}

// Main test driver
int main(int argc, char** argv) {
	FeetInches measure1(4, 10);
	printMeasure(measure1);
	measure1.setFeet(5);
	printMeasure(measure1);
	measure1.setInches(11);
	printMeasure(measure1);
	
	// Testing increment operators
	printMeasure(measure1++);
	printMeasure(measure1);
	printMeasure(++measure1);
	return 0;
}