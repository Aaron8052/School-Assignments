/*
Assignment7
Yu Jiang
11/10/2023
*/

#include <iostream>

using namespace std;

int main()
{
	bool joesGourmetBurgers = true;
	bool mainStreetPizzaCompany = true;
	bool cornerCafe = true;
	bool mamasFineItalian = true;
	bool theChef = true;
	
	bool vagetarian = false;
	bool vegan = false;
	bool glutenFree = false;
	
	
	
	string inputBuffer = "";
	
	cout << "Is anyone in your party a vagetarian? ";
	cin >> inputBuffer;
	
	vagetarian = inputBuffer == "yes";
	cin.clear();
	
	
	cout << "Is anyone in your party a vegan? ";
	cin >> inputBuffer;
	
	vegan = inputBuffer == "yes";
	cin.clear();
	
	
	cout << "Is anyone in your party a gluten free? ";
	cin >> inputBuffer;
	
	glutenFree = inputBuffer == "yes";
	cin.clear();
	
	
	
	
	joesGourmetBurgers = !vagetarian && !vegan && !glutenFree;
	mainStreetPizzaCompany = !vegan;
	//cornerCafe = true;
	mamasFineItalian = !vegan && !glutenFree;
	//theChef = true;
	
	cout << "\nHere are yiour choices:\n\n";
	
	if(joesGourmetBurgers)
		cout << "Joe's Gourmet Burgers - Vegetarian\n";
		
	if(mainStreetPizzaCompany)
		cout << "Main Street Pizza Company - Vegetarian\n";
		
	if(cornerCafe)
		cout << "Corner Cafe - Vegetarian\n";
		
	if(mamasFineItalian)
		cout << "Mama's Fine Italian - Vegetarian\n";
		
	if(theChef)
		cout << "The Chef's Kitchen - Vegtarian\n";
		
	return 1;
}