/*
	Name: Car Class
	Copyright: 2024
	Author: Yu Jiang
	Date: 12/05/24 13:57
	Description: Programming Challenge #3, "Car Class".
*/

#include <iostream>
using namespace std;

// Car Definition
class Car{
	private:
		int yearModel;
		string make;
		int speed;
	public:
		Car(int year, string make);
		int getYearModel();
		string getMake();
		int getSpeed();
		void accelerate();
		void brake();
};

// Print the car's current speed
void printCarSpeed(Car &car)
{
	cout << "Current Speed: " << car.getSpeed() << endl;
}

// Main test driver
int main(int argc, char** argv)
{
	Car myCar(2019, "Audi");
	const int ATTEMPTS = 5;
	for(int i = 0; i < ATTEMPTS; i ++)
	{
		myCar.accelerate();
		printCarSpeed(myCar);
	}
	for(int i = 0; i < ATTEMPTS; i ++)
	{
		myCar.brake();
		printCarSpeed(myCar);
	}
	return 0;
}

// Car Constructor
Car::Car(int year, string make)
{
	yearModel = year;
	
	// this->make = make;
	(*this).make = make;
	speed = 0;
}

// Get car's year model
int Car::getYearModel()
{
	return yearModel;
}

// Get the make of the car
string Car::getMake()
{
	return make;
}

// Get the car's current speed
int Car::getSpeed()
{
	return speed;
}

// Accelerate the car speed by 5
void Car::accelerate()
{
	speed += 5;
}

// Slows the car speed by 5
void Car::brake()
{
	speed -= 5;
}