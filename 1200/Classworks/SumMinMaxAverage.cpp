#include <iostream>

using namespace std;

int main()
{
	int input;
	
	cout << "Enter a sequence of positive  integers and type Q to quit: ";
	cin >> input;
	int sum = input;
	
	int max = input;
	int min = input;
	double average;
	int count = 1;
	while(cin >> input)
	{
		count ++;
		sum = sum + input;
		if(input > max)
		{
			max = input;
		}
		
		if(input < min)
		{
			min = input;
		}
	}
	if(count > 0)
	{
		average = sum / count;
		cout << "The average of the sequence of numbers is "
			 << average  << endl;
			 
		cout << "The maximum value is " << max << endl;
		cout << "The minimum value is " << min << endl;
	}
	else{
		cout << ""
	}
}