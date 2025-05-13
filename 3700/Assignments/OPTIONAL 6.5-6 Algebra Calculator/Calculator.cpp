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

void printIntro()
{
	std::cout << "Please enter an algebra expression, "
		<< "or type \"" << EXIT << "\" to exit."
		<< std::endl << "Expression: ";
}

void printResult(const double result)
{
	if (std::isnan(result) || std::isinf(result))
		std::cout << "Undefined";
	else std::cout << result;
	std::cout << std::endl << std::endl;
}

void printInvalidExpr()
{
	std::cout << "Invalid expression, "
		<< "please try again!"
		<< std::endl << std::endl;
}

void processInput(std::string& userInput)
{
	std::string postfixExpr;
	double result = 0.0;
	// Expression Validation
	try
	{
		Algebra alg;
		postfixExpr = alg.toPostfix(userInput);
		result = alg.evaluatePostfix(postfixExpr);
	}
	catch (std::logic_error& ex)
	{
		printInvalidExpr();
		return;
	}
	std::cout << "Postfix Expression: " << postfixExpr << std::endl;
	// Result Validation
	std::cout << "Result: ";
	printResult(result);
}

int main()
{
	std::string userInput;
	while (userInput != EXIT)
	{
		userInput.clear();
		printIntro();
		std::getline(std::cin, userInput);
		std::cin.clear();
		if (userInput == EXIT)
			break;
		processInput(userInput);
	}
	return 0;
}
