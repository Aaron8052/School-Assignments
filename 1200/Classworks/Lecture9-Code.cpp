/*Yu Jiang
Lecture9-Code #1
*/


#include <iostream>
using namespace std;

int main(){
	int attemps = 0;
	cout << "Attemps: ";
	cin >> attemps;
	
	int hens = 1, chicks = 0, eggs = 1;
	
	for(int i = 0; i < attemps; i++){
		
		hens += chicks;
		
	
		chicks = eggs;
		eggs = hens;
		
		printf("\nAttemp: %i\n", i+1);
		printf("Hens = %i\n", hens);
		printf("Chicks = %i\n", chicks);
		printf("Eggs = %i\n", eggs);
	}
	
	system("pause");
	
	return 0;
}