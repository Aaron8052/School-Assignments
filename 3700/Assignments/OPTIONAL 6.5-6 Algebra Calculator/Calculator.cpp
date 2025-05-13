/*
    Name: Calculator
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/12/2025
    Description: The C++ implementation file for the Calculator class.
*/

#include <cmath>
#include <iostream>
#include <string>

#include "Algebra.h"

const std::string EXIT = "quit";

int main()
{
	std::string userInput = "";
	Algebra alg;
	while (userInput != EXIT)
	{
		userInput.clear();
		std::cout << "Please enter an algebra expression, "
			<< "or type \"" << EXIT << "\" to exit."
			<< std::endl << "Expression: ";
		std::getline(std::cin, userInput);
		std::cin.clear();
		if (userInput == EXIT)
			break;
		std::string postfixExpr = "";
		double result = 0.0;

		// Expression Validation
		try
		{
			postfixExpr = alg.toPostfix(userInput);
			result = alg.evaluatePostfix(postfixExpr);
		}
		catch (std::logic_error& ex)
		{
			std::cout << "Invalid expression, "
					<< "please try again!"
					<< std::endl << std::endl;
			continue;
		}
		std::cout << "Postfix Expression: " << postfixExpr
					<< std::endl;

		// Result Validation
		std::cout << "Result: ";
		if (std::isnan(result) || std::isinf(result))
			std::cout << "Undefined";
		else
			std::cout << result;
		std::cout << std::endl << std::endl;
	}
	return 0;
}
