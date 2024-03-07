#include <iostream>
using namespace std;

void getScores(double scores[]);
void displayScores(const double scores[]);
const int SCORES = 4;
int main()
{
	
	double testScores[SCORES] = {0.0, 0.0, 0.0, 0.0};
	char ch;
	do
	{	
		getScores(testScores);
		cout << "[ " << testScores[0];
		for(int i = 1; i < SCORES; i++)
		{
			cout << ", " << testScores[i] << " ";
		}
		cout << "]\n";
		cout << "Do you test it again? (y/Y): ";
		cin >> ch;
	}
	while(ch == 'y'|| ch == 'Y');
	
	displayScores(testScores);
	
	return 0;
}

/**This function prompts the user and gets data.
@param testScores is an array of testScores to be filled
@param SCORES, the size of the array
*/
void getScores(double scores[])
{
	for(int score = 0; score < SCORES; score++)
	{
		cout << "Enter Test" << (score + 1) << " score: ";
		cin >> scores[score];
	}
}
void displayScores(const double scores[])
{
	cout << endl << endl;
	for(int i = 0; i < SCORES; i++)
	{
		cout << "Test " << (i + 1) << scores[i] << endl;
	}
}