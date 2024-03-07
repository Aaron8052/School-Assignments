/*Yu Jiang
Assignment 3
9/27/2023
*/

#include <iostream>

using namespace std;

void CalculateAmount(float amount = 0, float durationInMonths = 0, float interestRate = 0)
{	
	//Normalized duration in year
	float durationInYear = durationInMonths / 12;
	
	//Total interest rate in this duration
	float totalRate = (interestRate / 100) * durationInYear;

	//total interest $
	float requiredAmount = amount / (1 - totalRate);
	//Calculate required amount of $ needed to loan if we want to get the target amount of money
	float interest = requiredAmount * totalRate;
	float amountAfterInterest = requiredAmount - interest;
	float monthlyLoanPayment = requiredAmount / durationInMonths;
	
	printf("\nTarget Amount: %.2f$\nDuration: %.0f months\nInterest Rate: %.1f%\n\n", 
			amount,
			durationInMonths,
			interestRate);
			
	//Output results
	printf("\nAmount need to loan %.2f$\nInterest: %.2f$\nAmount After Interest: %.2f$\nMonthly Load Payment: %.2f$\n\n", 
			requiredAmount,
			interest, 
			amountAfterInterest, 
			monthlyLoanPayment);
}

int main()
{
	cout << "Test Case 0 ---------------\n";
	CalculateAmount(775, 18, 15);
	
	cout << "Test Case 1 ---------------\n";
	CalculateAmount(1100, 18, 15);
	
	cout << "Test Case 2 ---------------\n";
	CalculateAmount(2500, 18, 15);
	
	cout << "Test Case 3 ---------------\n";
	CalculateAmount(2500, 18, 15);
	
	cout << "Test Case 4 ---------------\n";
	CalculateAmount(2500, 18, 10);
	
	cout << "Test Case 5 ---------------\n";
	CalculateAmount(2500, 18, 20);
	
	cout << "Test Case 6 ---------------\n";
	CalculateAmount(2500, 18, 55);
	
	cout << "Test Case 7 ---------------\n";
	CalculateAmount(1000, 12, 15);
	
	cout << "Test Case 8 ---------------\n";
	CalculateAmount(1000, 6, 15);
	
	cout << "Test Case 9 ---------------\n";
	CalculateAmount(1000, 24, 15);
	
	system("pause");
	
}

