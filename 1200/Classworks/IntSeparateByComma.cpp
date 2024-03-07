/*
Yu Jiang
This problem reads a number greater than or equal to 1000
and less than or equal to 999999 and puts a comma separating
the thousands.*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Please enter an integer between 1,000 and 999,999: ";
	string digit  = "";
	

	cin >> digit; 
	
	int length = digit.length();
	
	string part1 = digit.substr(0, length - 3);
	string part2 = digit.substr(length -3, 3);
	
	digit = part1 + "," + part2;
	cout << digit << endl;
	
	system("pause");
	return 0;
}