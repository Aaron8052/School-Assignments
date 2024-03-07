//This program shows how to swap values of two variables

#include <iostream>
using namespace std;

void swapValues(int a, int b);

int main(){
	//Get two integer values from user
	int m = 0, n = 0;
	cout << "Enter two integer values:   ";
	cin >> m >> n;
	
	cout << "\n\nValues of m and n before swap.\n";
	cout << "m: " << m << "\n";
	cout << "n: " << n << endl;
	
	int temp = m;
	m = n;
	n = temp;
	
	cout << "Value of m after swap: " << m << endl;
	cout << "Value of n after swap: " << n << endl;
	return 0;
}