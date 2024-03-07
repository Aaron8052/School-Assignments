#include <iostream>
#include <string>
using namespace std;


const int LENGTH = 10;
const int SIZE = 5;
const int STUDENTS = 5;
const int SCORES = 4;


int main()
{
	int numbers[LENGTH];
	double values[SIZE];
	string names[STUDENTS];
	double scores[SCORES];
	
	for(int i = 0; i < LENGTH; i++)
	{
		numbers[i] = i * i;
	}
	for(int i = 0; i < LENGTH; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < SIZE; i++)
	{
		values[i] = i;
	}
	for(int i = 0; i < SIZE; i++)
	{
		cout << values[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < STUDENTS; i++)
	{
		string name = "";
		cout << "Enter student "<< (i + 1) << "'s name: ";
		cin >> name;
		names[i] = name;
	}
	for(int i = 0; i < STUDENTS; i++)
	{
		cout << names[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < SCORES; i++)
	{
		scores[i] = i * 100;
	}
	for(int i = 0; i < SCORES; i++)
	{
		cout << scores[i] << " ";
	}
	cout << endl;
	return 0;
}