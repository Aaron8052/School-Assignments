/*Yu Jiang
Lecture9-Code #1
*/


#include <iostream>
using namespace std;

int main()
{
		
	int hens = 1;
	int chicks = 0;
	int eggs = 1;
	
	hens = hens + chicks;
	chicks = eggs;
	eggs = hens;
	
	hens = hens + chicks;
	chicks = eggs;
	eggs = hens;
	
	hens = hens + chicks;
	chicks = eggs;
	eggs = hens;
	
	hens = hens + chicks;
	chicks = eggs;
	eggs = hens;
	
	hens = hens + chicks;
	
	cout << "Hens = " << hens << '\n';
	cout << "Chicks = " << chicks << '\n';
	cout << "Eggs = " << eggs << '\n';
	
	return 0;

}