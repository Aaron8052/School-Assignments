/*
	Name: Assignment: 14.4: NumDays Class
	Copyright: 2024
	Author: Yu Jiang
	Date: 18/05/24 17:50
	Description: NumDays Class
*/

#include <iostream>
using namespace std;

class NumDays
{
	const int WORK_HOURS = 8;
	private:
		float hours;
	public:
		NumDays(float hours);
		float getHours();
		float getDays();
		void setHours(float hours);
		void setDays(float days);
		NumDays operator + (const NumDays &right);
		NumDays operator - (const NumDays &right);
		NumDays operator ++ ();
		NumDays operator ++ (int);
		NumDays operator -- ();
		NumDays operator -- (int);
};

// Output NumDays / test getHours and getDays accessors
void printNumDays(NumDays numDays)
{
	cout << numDays.getHours() << " Hours " 
		 << numDays.getDays() << " Days" << endl;
}

// Main test driver
int main(int argc, char** argv)
{
	NumDays test(16);
	printNumDays(test);
	test.setDays(3.1);
	printNumDays(test);
	test.setHours(20);
	printNumDays(test);
	NumDays test2(10);
	NumDays test3 = test + test2;
	printNumDays(test3);
	NumDays test4 = test - test2;
	printNumDays(test4);
	printNumDays(++test);
	printNumDays(test++);
	printNumDays(--test);
	printNumDays(test--);
	printNumDays(test);
	return 0;
}

// Constructor
NumDays::NumDays(float hours)
{
	this -> hours = hours;
}

// Returns num of hours
float NumDays::getHours()
{
	return this -> hours;
}

// Returns num of days
float NumDays::getDays()
{
	return this -> hours / NumDays::WORK_HOURS;
}

// Set hours
void NumDays::setHours(float hours)
{
	this -> hours = hours;
}

// Set days
void NumDays::setDays(float days)
{
	float hrs = days * NumDays::WORK_HOURS;
	this -> hours = hrs;
}

// overload + operator
NumDays NumDays::operator + (const NumDays &right)
{
	NumDays temp(hours);
	temp.hours += right.hours;
	return temp;
}

// overload - operator
NumDays NumDays::operator - (const NumDays &right)
{
	NumDays temp(hours);
	temp.hours -= right.hours;
	return temp;
}

// overload Prefix ++ operator
NumDays NumDays::operator ++ ()
{
	hours ++;
	return *this;
}

// overload Postfix ++ operator
NumDays NumDays::operator ++ (int)
{
	NumDays temp(this -> hours);
	hours ++;
	return temp;
}

// overload -- operator
NumDays NumDays::operator -- ()
{
	hours --;
	return *this;
}

// overload Postfix -- operator
NumDays NumDays::operator -- (int)
{
	NumDays temp(this -> hours);
	hours --;
	return temp;
}