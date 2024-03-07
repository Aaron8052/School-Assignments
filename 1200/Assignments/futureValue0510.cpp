/*
Yu Jiang
10/09/2023
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	//Declear variables
	
	double 	monthlyPaymentAmount = 250.00,//PMT
		  	annualPercentageRate = 0.12,//APR
		  	futureValue = 0,//FV
		  	totalAmountPaid = 0,
		  	interestAccumulated = 0,
			monthlyApr = 0;//monthly APR
		  
		  
	int	 	numberOfYears = 35, //Years, 
			n = 12; //payment periods per year
	
	
	monthlyApr = annualPercentageRate / n;
	
	//Set float point precision;
	cout << std::fixed << std::setprecision(2);
	
	cout << "Enter monthly payment amount: ";
	cin >> monthlyPaymentAmount;
	
	cout << "\nAnnual percentage rate: ";
	cin >> annualPercentageRate;
	
	cout << "\nNumber of years: ";
	cin >> numberOfYears;
	
	cout << "\n\nRegular monthly payment amount (PMT): \t$" << setw(16) << monthlyPaymentAmount;
	cout << "\nAnnual percentage rate as a decimal: \t$" << setw(16) << annualPercentageRate;
	cout << std::setprecision(0);
	cout << "\nNumber of years of savings: \t\t" << setw(17) << numberOfYears;
	
	
	
	
	//Cal futureValue
	futureValue = monthlyPaymentAmount * ((pow((1 + monthlyApr), n * numberOfYears)) / monthlyApr);
	
	cout << std::setprecision(2);
	cout << "\nThe future value of the savings plan: \t$" << setw(16) << futureValue;
	
	totalAmountPaid = monthlyPaymentAmount * n * numberOfYears;
	
	cout << "\nTotal amount paid by the user: \t\t$" << setw(16) << totalAmountPaid;
	cout << "\nAmount of interest accumulated: \t$" << setw(16) << futureValue - totalAmountPaid;
	cout.clear();
	
	/*
	// Test Case 1 :
	cout << "\n\nRegular monthly payment amount (PMT): \t$" << setw(16) << 300;
	cout << "\nAnnual percentage rate as a decimal: \t$" << setw(16) <<  0.10;
	cout << "\nNumber of years of savings: \t\t" << setw(17) << 20;
	cout << "\nThe future value of the savings plan: \t$" << setw(16) << 326776.61;
	cout << "\nTotal amount paid by the user: \t\t$" << setw(16) <<  72000.00;
	cout << "\nAmount of interest accumulated: \t$" << setw(16) << 254776.61;
	cout.clear();
	
	// Test Case 2 :
	cout << "\n\nRegular monthly payment amount (PMT): \t$" << setw(16) << 400;
	cout << "\nAnnual percentage rate as a decimal: \t$" << setw(16) <<  0.20;
	cout << "\nNumber of years of savings: \t\t" << setw(17) << 25;
	cout << "\nThe future value of the savings plan: \t$" << setw(16) << 791538.65;
	cout << "\nTotal amount paid by the user: \t\t$" << setw(16) << 120000.00;
	cout << "\nAmount of interest accumulated: \t$" << setw(16) << 671538.65;
	
	// Test Case 3 :
	cout << "\n\nRegular monthly payment amount (PMT): \t$" << setw(16) << 600;
	cout << "\nAnnual percentage rate as a decimal: \t$" << setw(16) <<  0.16;
	cout << "\nNumber of years of savings: \t\t" << setw(17) << 31;
	cout << "\nThe future value of the savings plan: \t$" << setw(16) << 2430537.34;
	cout << "\nTotal amount paid by the user: \t\t$" << setw(16) << 223200.00;
	cout << "\nAmount of interest accumulated: \t$" << setw(16) << 2207337.34;
	cout.clear();
	
	
	// Test Case 4 :
	cout << "\n\nRegular monthly payment amount (PMT): \t$" << setw(16) << 250;
	cout << "\nAnnual percentage rate as a decimal: \t$" << setw(16) <<  0.12;
	cout << "\nNumber of years of savings: \t\t" << setw(17) << 37;
	cout << "\nThe future value of the savings plan: \t$" << setw(16) << 2073146.38;
	cout << "\nTotal amount paid by the user: \t\t$" << setw(16) <<  223200.00;
	cout << "\nAmount of interest accumulated: \t$" << setw(16) << 1962146.38;
	cout.clear();
	
	// Test Case 5 :
	cout << "\n\nRegular monthly payment amount (PMT): \t$" << setw(16) << 250;
	cout << "\nAnnual percentage rate as a decimal: \t$" << setw(16) <<  0.12;
	cout << "\nNumber of years of savings: \t\t" << setw(17) << 40;
	cout << "\nThe future value of the savings plan: \t$" << setw(16) << 2966193.13;
	cout << "\nTotal amount paid by the user: \t\t$" << setw(16) <<  120000.00;
	cout << "\nAmount of interest accumulated: \t$" << setw(16) << 2846193.13;
	cout.clear();
	
	// Test Case 6 :
	cout << "\n\nRegular monthly payment amount (PMT): \t$" << setw(16) << 250;
	cout << "\nAnnual percentage rate as a decimal: \t$" << setw(16) <<  0.12;
	cout << "\nNumber of years of savings: \t\t" << setw(17) << 45;
	cout << "\nThe future value of the savings plan: \t$" << setw(16) << 5388673.26;
	cout << "\nTotal amount paid by the user: \t\t$" << setw(16) <<  135000.00;
	cout << "\nAmount of interest accumulated: \t$" << setw(16) << 5253673.26;
	cout.clear();
	*/
	
	return 0;
}