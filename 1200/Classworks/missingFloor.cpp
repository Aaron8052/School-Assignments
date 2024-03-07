//This program demonstrate an if statement

#include <iostream>

using namespace std;

int main()
{
	//prompt the user for the floor
	cout << "Enter your floor: ";
	
	int floor;
	
	cin >> floor;
	
	int actualFloor = floor;
	
	if(floor > 13)
	{
		actualFloor--;
	}	
	cout << "Elevator take you to actual floor: " << actualFloor << endl;
	return 0;
}