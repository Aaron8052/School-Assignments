//This program shows how to generate random number using rand()
//function. You need to include the header line <cstdlib>

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	unsigned seed = time(0);//time(NULL);
	srand(seed);
	
	int min = 1;
	int max = 6;
	int range = max - min;
	
	int r = (rand() % range) + min; //The num we get remains the same if rand() < range
	
	cout << r << endl;
	
	cout << rand () % range + 1 << endl;
	cout << rand () % range + 1 << endl;
	cout << rand () % range + 1 << endl;
	
	min = 40;
	max = 100;
	range = (max - min) + 1;
	cout << rand () % range + 1 << endl;
	cout << rand () % range + 1 << endl;
	cout << rand () % range + 1 << endl;
	
	//Flip a coin see how many time 1 comes
	
	range = 2;
	cout rand() % range << endl;
	cout rand() % range << endl;
	cout rand() % range << endl;
	return 0;
}