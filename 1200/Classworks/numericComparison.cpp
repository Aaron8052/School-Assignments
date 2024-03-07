//This program compares integers and floating point numbers

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Comparing integers
	int p = 4;
	int q = 16;
	if(p * p == q)
	{
		cout << "4 times 4 is 16\n";
	}	
	//Floating point numbers
	
	double x = sqrt(7);
	double y = 7;
	if(x * x == y)
	{
		cout << "x*x is equal to y." << endl;
	}
	else
	{
		cout << fixed << setprecision(18);
		cout << x*x << " is not equal to " << y << endl;
	}
	const double EPSILON = 1.0E-14;
	
	if(abs(x*x - y ) <= EPSILON)
	{
		cout << "x*x is approximately equal to y\n";
	}
	return 0;
}
