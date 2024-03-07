/*
Yu Jiang
10/2/2023
This program computes the sum of odd numbers only
*/

#include <iostream>

using namespace std;


int main()
{
	int a = 15, b = 8, c = 19, d = 16, n = 0;
	
	cout << "a: ";
	cin >> a;
	
	cout << "b: ";
	cin >> b;
	
	cout << "c: ";
	cin >> c;
	
	cout << "d: ";
	cin >> d;
	
	
	n += a * (a % 2);
	n += b * (b % 2);
	n += c * (c % 2);
	n += d * (d % 2);
	
	cout << "The sum of odd numbers among abcd is: " << n << endl;
	
	system("pause");
	
	return 0;
}