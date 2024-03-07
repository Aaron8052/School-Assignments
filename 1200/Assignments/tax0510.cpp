/*
Yu Jiang
10/26/2023
*/

#include <iostream>
#include <iomanip> 

using namespace std;

double GetTax(double income, const double taxRate10, const double taxRate12, const double taxRate22)
{
	//Check for 0 income
	if(income <= 0)
		return 0;
	
	double totalTex = 0;
	
	//Calculate For the first 10% Tax
	
	//Get the smaller amount from income and Tax Rate 10%;
	//min(income, taxRate10);
	double tempVarIncome = income < taxRate10 ? income : taxRate10;

	//add the tax for the 10% part into total tax
	totalTex += tempVarIncome * 0.10;
	
	//Substract taxRate10 from income
	income -= taxRate10;
	
	//if no remaining income then return the tax
	if(income <= 0)
		return totalTex;
	
	
	
	
	//the amount of money beween Tax Rate 10% - 12%
	double tempVarGapBetween2Rates = taxRate12 - taxRate10;
	
	//Get the smaller one from remaining amount of income and amount between Tax Rate 10% - 12%;
	//min(income, tempVarGapBetween2Rates);
	tempVarIncome = income < tempVarGapBetween2Rates ? income : tempVarGapBetween2Rates;
	
	//add the tax for the 12% part into total tax
	totalTex += tempVarIncome * 0.12;
	
	//Substract taxRate12 from income
	income -= tempVarIncome;
	
	//if no remaining income then return the tax
	if(income <= 0)
		return totalTex;
	
	
	
	
	//the amount of money beween Tax Rate 12% - 22%
	tempVarGapBetween2Rates = taxRate22 - taxRate12;
	
	//Get the smaller amount from remaining amount of income and amount between Tax Rate 12% - 22%;
	//min(income, tempVarGapBetween2Rates);
	tempVarIncome = income < tempVarGapBetween2Rates ? income : tempVarGapBetween2Rates;
	
	//add the tax for the 22% part into total tax
	totalTex += tempVarIncome * 0.22;

	return totalTex;
}

float GetTaxForSingleFiler(const double income)
{
	return GetTax(income, 11000, 44725, 95375);
}

float GetTaxForMarriedIndividuals(const double income)
{
	
	return GetTax(income, 22000, 89450, 190750);
}

float GetTaxForHeadOfHouseholds(const double income)
{
	
	return GetTax(income, 15000, 59850, 95350);
}

int main()
{
	double income = 0;
	
	cout << "Enter your income: ";
	cin >> income;
	
	cout << fixed;
	
	cout << "\nTax for Single: \t\t" 
		 << setw(10) << setprecision(2) << GetTaxForSingleFiler(income);
		 
	cout << "\nTax for Married Individuals: \t" 
		 << setw(10) << setprecision(2) << GetTaxForMarriedIndividuals(income);
		 
	cout << "\nTax for Head of Households: \t" 
		 << setw(10) << setprecision(2) << GetTaxForHeadOfHouseholds(income);
	
	return 0;
} 