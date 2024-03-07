/*
Yu Jiang
11/03/2023
This program calculates customer's monthly bill and how much they can save by choosing other plans.
*/

#include <iostream>
#include <cstring>

using namespace std;

const float PLAN_A_MONTYLY_FEE = 39.99;
const float PLAN_A_GIGABYTES = 4.0;
const float PLAN_A_ADDITIONAL_DATA_FEE = 10;

const float PLAN_B_MONTYLY_FEE = 59.99;
const float PLAN_B_GIGABYTES = 8.0;
const float PLAN_B_ADDITIONAL_DATA_FEE = 5.00;

const float PLAN_C_MONTYLY_FEE = 69.99;
const float PLAN_C_GIGABYTES = -1.0;
const float PLAN_C_ADDITIONAL_DATA_FEE = 0;

float CalculateTotalAmountDue(float monthlyFee, float dataUsed, float dataIncluded, float additionalDataFee)
{
	
	//monthly Fee + total additional Data Fee
	return monthlyFee + ((dataUsed < dataIncluded || dataIncluded < 0) ? 0 : ((dataUsed - dataIncluded) * additionalDataFee));
}


int main()
{
	
	string userPlan = "";
	
	//prompt user to enter their plan
	cout << "Enter the plan you are using A | B | C\n";
	
	getline(cin, userPlan);
	
	//Check if user entered nothing;
	if(userPlan.empty())
	{
		cout << "The plan you have entered is not valid!\n";
		return 0;
	}
	
	float dataUsed = 0;
	
	//prompt user to enter their data usage
	cout << "Please enter the data you have used (GB): ";
	cin >> dataUsed;
	
	
	
	float planATotal = CalculateTotalAmountDue(PLAN_A_MONTYLY_FEE, dataUsed, PLAN_A_GIGABYTES, PLAN_A_ADDITIONAL_DATA_FEE);
	float planBTotal = CalculateTotalAmountDue(PLAN_B_MONTYLY_FEE, dataUsed, PLAN_B_GIGABYTES, PLAN_B_ADDITIONAL_DATA_FEE);
	float planCTotal = CalculateTotalAmountDue(PLAN_C_MONTYLY_FEE, dataUsed, PLAN_C_GIGABYTES, PLAN_C_ADDITIONAL_DATA_FEE);
	
	//PlanA
	if(userPlan == "A" || userPlan == "a")
	{
		cout << "Plan A monthly due: $" << planATotal << endl;
		
		//Check how much they can save by choosing Plan B
		if(planATotal > planBTotal)
		{
			cout << "You can save $" << planATotal - planBTotal << " by choosing Plan B" << endl;
		}
		
		//Check how much they can save by choosing Plan C	
		if(planATotal > planCTotal)
		{
			cout << "You can save $" << planATotal - planCTotal << "by choosing Plan C" << endl;
		}
	}
	//PlanB
	else if(userPlan == "B" || userPlan == "b")
	{
		cout << "Plan B monthly due: $" << planBTotal << endl;
			
		//Check how much they can save by choosing Plan A
		if(planBTotal > planATotal)
		{
			cout << "You can save $" << planBTotal - planATotal << "by choosing Plan A" << endl;
		}
		
		//Check how much they can save by choosing Plan C
		if(planBTotal > planCTotal)
		{
			cout << "You can save $" << planBTotal - planCTotal << "by choosing Plan C" << endl;
		}
	}
	//PlanC
	else if(userPlan == "C" || userPlan == "c")
	{
		cout << "Plan C monthly due: $" << planCTotal << endl;
			
		//Check how much they can save by choosing Plan A
		if(planCTotal > planATotal)
		{
			cout << "You can save $" << planCTotal - planATotal << "by choosing Plan A" << endl;
		}
		
		//Check how much they can save by choosing Plan B	
		if(planCTotal > planBTotal)
		{
			cout << "You can save $" << planCTotal - planBTotal << "by choosing Plan B" << endl;
		}
	}
	else
	{
		cout << "The plan you have entered is not valid!\n";
		return 0;
	}
	
	return 1;
}