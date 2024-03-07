//This program 

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	string s = "320";
	string t = "30";
	
	if (s < t)
	{
		cout <<  s << " comes before " << t << endl;
	}
	else if (s > t)
	{
		cout <<  s << " comes after " << t << endl;
	}
	else
	{
		cout <<  s << " is same as " << t << endl;
	}
	return 0;
}