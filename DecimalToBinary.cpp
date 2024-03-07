#include <iostream>
using namespace std;

string ToBinary(int num, int length)
{
	string str;
	
	while(num > 0){
		
		//divide the num each time by 2 and insert result in front of the string
		str.insert(0, 1,  ((num % 2) == 0 ? '0':'1'));//get remainder of num and insert 0 / 1
		num /= 2;//divide num by 2
	}
	
	//insert 0 for empty digits
	if(str.size() < length)
		str.insert(0, length - str.size(), '0');
		
		
	return str;
}
	

int main()
{
	cout << "[Decimal to binary converter]\n\n";
	
	int decimal, digit;
	
	cout << "Max decimal to convert: ";
	cin >> decimal;
	
	cout << "\nDigits: ";
	cin >> digit;
	
	cout << "\n-----------------\n";
	cout << "Decimal\t Binary \n";
	cout << "-----------------\n";
	
	//create a for loop to convert each number to binary
	for(int i = 0; i <= decimal; i++)
	{
		string binary = ToBinary(i, digit);
		cout << i << "\t " <<  binary << "       \n";
		
		if(i == decimal)
			cout << "\n";
	}
	
	//pause the program to avoid quitting automatically
	system("pause");
	
	return 0;
}
