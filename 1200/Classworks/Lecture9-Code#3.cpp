/*Yu Jiang
Lecture9-Code #3
*/

#include <iostream>

using namespace std;

int main()
{
	float total = 750 * 35;
	float commission = total * 0.02f;
 	
	cout << "The amount paid for the stock alone without commission: $" << total;
	cout << "\nThe amount of commission: $" << commission;
	total += commission;
	cout << "\nThe total amount paid: $" << total;
	
	return 0;
}