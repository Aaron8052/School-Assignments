/*
	Name: VitalStatsClass
	Copyright: 2022
	Author: Yu Jiang
	Date: 14-09-22 18:31
	Description: Write & test a class for recording people's vital stats.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Vital stats class
class VitalStats {

	// Fill in data definitions
	private:
		string name;
		int height;
		float weight;
	// Fill in code for constructor
	public:
		VitalStats(string, int, float);
	// Fill in code for accessors
		string getName();
		int getHeight();
		float getWeight();
	// Fill in code for mutators
		void setName(string name);
		void setHeight(int height);
		void setWeight(float weight);
	// Fill in code for calculator function
		float calcBMI();
};

// Main test driver
int main(int argc, char** argv) {

	// Create three records
	const int NUM_PATIENTS = 3;
	VitalStats records[NUM_PATIENTS] = {
		VitalStats("Alice Smith", 50, 100.0),
		VitalStats("Bob Johnson", 70, 170.2),
		VitalStats("Carol Williams", 72, 134.5)
	};
	
	// Print table of records
	cout << fixed << showpoint << setprecision(2);	
	cout << left << setw(16) << "Name" << setw(8) << "Height" 
		<< setw(8) << "Weight" << setw(8) << "BMI" << endl;
	for (int i = 0; i < NUM_PATIENTS; i++) {
		cout << setw(16) << records[i].getName()
			<< setw(8) << records[i].getHeight()
			<< setw(8) << records[i].getWeight()
			<< setw(8) << records[i].calcBMI() << endl;
	}
	return 0;
}

// Constructor
VitalStats::VitalStats(string name, int height, float weight)
{
	this->name = name;
	this->height = height;
	this->weight = weight;
}

// get height in inches
int VitalStats::getHeight()
{
	return height;
}

// get weight in pounds
float VitalStats::getWeight()
{
	return weight;
}

// get name
string VitalStats::getName()
{
	return name;
}

// set name
void VitalStats::setName(string name)
{
	this->name = name;
}

// set height
void VitalStats::setHeight(int height)
{
	this->height = height;
}

// set weight
void VitalStats::setWeight(float weight)
{
	this->weight = weight;
}

// Calculates BMI of the person
float VitalStats::calcBMI()
{
	return weight / pow(height, 2) * 703;
}
