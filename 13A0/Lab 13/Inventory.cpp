

#include <iostream>
#include <fstream>
using namespace std;


// This program defines a class called Inventory that has itemnumber (which
// contains the id number of a product) and numofitem (which contains the
// quantity on hand of the corresponding product)as private data members.
// The program will read these values from a file and store them in an
// array of objects (of type Inventory).  It will then print these values
// to the screen.

// Example: Given the following data file:
//     986 8
//     432 24
// This program reads these values into an array of objects and prints the
// following:
//     Item number 986 has 8 items in stock
//     Item number 432 has 24 items in stock


const int NUMOFPROD = 10;   // This holds the number of products a store sells

class Inventory {
	public:

		void setId(int item);
		void setAmount(int num);
		void display();



	private:

		int  itemNumber;  		// This is an id number of the product
		int  numOfItem;   		// This is the number of items in stock

};


int main() {

	ifstream infile;	      // Input file to read values into array
	infile.open("Inventory.dat");

	// Fill in the code that declares an array of objects of class Inventory
	// called products. The array should be of size NUMOFPROD
	Inventory products[NUMOFPROD];

	int pos;                   // loop counter
	int id;                    // variable holding the id number
	int total;                 // variable holding the total for each id number

	// Fill in the code that will read inventory numbers and number of items
	// from a file into the array of objects. There should be calls to both
	// SetId and SetAmount member functions somewhere in this code.
	// Example: products[pos].getId(id); will be somewhere in this code
	for (pos = 0; pos < NUMOFPROD; pos ++) {
		infile >> id;
		products[pos].setId(id);
		infile >> total;
		products[pos].setAmount(total);
	}

	// Fill in the code to print out the values (itemNumber and numOfItem) for
	// each object in the array products.
	// This should be done by calling the member function display within a loop
	for (pos = 0; pos < NUMOFPROD; pos ++) {
		products[pos].display();
	}
	return 0;

}


// Write the implementations for all the member functions of the class.
void Inventory::setId(int item) {
	itemNumber = item;
}

void Inventory::setAmount(int num) {
	numOfItem = num;
}
//Item number 986 has 8 items in stock
//     Item number 432 has 24 items in stock
void Inventory::display(){
	cout << "Item number " << itemNumber << " has " << numOfItem << " items in stock\n";
}