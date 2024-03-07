//This program demonstrates how generate 0 1 matrices.

#include <iostream>
using namespace std;


int main()
{
	int lines = 0;
	
	cout << "Height: ";
	cin >> lines;
	cout << endl;
	
	int spaces = 0;
	
	for (int i = lines; i >= 0; i--)
	{
		int stars = (i * 2) - 1;
		
		for(int j = 0; j < spaces; j++)
		{
			cout << " ";
		}
		
		for(int s = 0; s < stars; s++)
		{
			cout << "*";
		}
		
		cout <<endl;
		spaces ++;
	}
}