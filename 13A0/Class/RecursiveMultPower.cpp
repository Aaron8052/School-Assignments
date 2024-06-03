#include <iostream>
using namespace std;

// Recusive multiply
int mult(int x, int y)
{
	return (x <= 0 || y <= 0) ? 0 : mult(x - 1, y) + y;
}

int power(int x, int y){
	if(y <= 0){
		return 1;
	}
	
	return mult(power(x, y - 1), x);
}

int main(){
	
	// Test multiplication
	cout << "5 x 3 = " << mult(5, 3) << endl;
	cout << "3 x 0 = " << mult(3, 0) << endl;
	cout << "0 x 12 = " << mult(0, 12) << endl;
	cout << "100 x 2 = " << mult(100, 2) << endl;
	cout << "6 x 8 = " << mult(6, 8) << endl;
	cout << "2 ^ 5 : " << power(2, 5) << endl;
	cout << "2 ^ 0 : " << power(2, 0) << endl;
	cout << "10 ^ 1 : " << power(10, 1) << endl;
}
