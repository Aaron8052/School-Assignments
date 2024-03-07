/*Yu Jiang
09/21/2023
This program outputs the gas elements that the planets have.*/

#include <iostream>
using namespace std;

/*void PrintF(const char** args){
	printf("%s \t| %s \t| %s \t|\n", args[0], args[1], args[2]);
}*/

int main(){
	/*const char* header[] = {"Planet Name", "Primary atmospheric gas", "Secondary atmospheric gas"};
	PrintF(header);*/
	
	cout << "---------------------------------------------------------------------------------\n";
	cout << "Planet Name \t| Primary atmospheric gas \t| Secondary atmospheric gas \t|\n";
	cout << "---------------------------------------------------------------------------------\n";
	cout << "Jupiter \t| hydrogen(H2) \t\t\t| helium(He) \t\t\t|\n";
	cout << "Saturn \t\t| hydrogen(H2) \t\t\t| helium(He) \t\t\t|\n";
	cout << "Uranus \t\t| hydrogen(H2) \t\t\t| helium(He) \t\t\t|\n";
	cout << "Neptune \t| hydrogen(H2) \t\t\t| helium(He) \t\t\t|\n";
	cout << "Venus \t\t| dioxide (CO2) \t\t| Nitrogen (N2) \t\t|\n";
	cout << "Mars \t\t| dioxide (CO2) \t\t| Nitrogen (N2) \t\t|\n";
	cout << "Earth \t\t| Nitrogen(N2) \t\t\t| Oxygen (O2) \t\t\t|\n";
	
	system("pause");
	
	return 0;
}