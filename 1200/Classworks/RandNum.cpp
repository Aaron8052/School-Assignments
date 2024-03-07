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
	
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
}