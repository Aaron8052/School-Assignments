#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;



int main()
{
	ofstream outstream;
	string fname = "numbers.txt";
	outstream.open(fname);
	if(outstream.fail()){
		outstream << "The file didn't open!\n";
		exit(1);
	}
	
	
	outstream << 12 << "\n" << 14 << "\n" << 16 << "\n" << 18 << "\n";	
	outstream.close();
	
	ifstream instream;
	instream.open(fname);
	
	if(instream.fail())
	{
		cout << "File didn't open!\n";
		exit(1);
	}
	int x;
	while(instream >> x)
	{
		cout << x << endl;
	}
	instream.close();
	return 0;
}