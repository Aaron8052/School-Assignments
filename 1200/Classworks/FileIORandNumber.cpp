#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN = 1, MAX = 100, NUMBERS = 100;

int GetRandNumber(int i )
{
	unsigned seed = time(0) + i;
	
	srand(seed);
	
	int range = MAX - MIN + 1;
	
	return rand() % range + MIN;
}


int main()
{
	ofstream writer;
	string fname = "randNumbers.txt";
	writer.open(fname);
	
	if(writer.fail()){
		writer << "The file didn't open!\n";
		exit(1);
	}
	
	
	for(int i = 0; i < NUMBERS; i++)
	{
		writer << GetRandNumber(i) << "\n";
	}
	

	writer.close();
	
	ifstream reader;
	reader.open(fname);
	
	if(reader.fail())
	{
		cout << "File didn't open!\n";
		exit(1);
	}
	int x;
	while(reader >> x)
	{
		cout << x << endl;
	}
	reader.close();
	return 0;
}