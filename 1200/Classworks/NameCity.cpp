#include <iostream>

using namespace std;

int main()
{
	
	int score = 0;
	
	cout << "Score: ";
	cin >> score;

	cin.ignore(100, '\n');
	
	string name = "";
	cout << "\nEnter your name :";
	getline(cin, name);
	
	cout << "\nEnter the name of the city you live in : ";
	
	string city = "";
	
	getline(cin, city);
	
	cout << "Hello, your name is " << name 
		<< ". You live in " << city << endl;
	cout << "Your score is " << score << endl;
	return 0;
}