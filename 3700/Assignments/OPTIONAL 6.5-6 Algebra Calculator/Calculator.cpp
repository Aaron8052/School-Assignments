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
	std::cout
		<< "[Algebra Calculator]" << std::endl
		<< "Please enter an algebra expression, "
		<< "or type \"" << EXIT << "\" to exit."
		<< std::endl << "Expression: ";
}

void printResult(const double result)
{
	std::cout << "Result: ";
	if (std::isnan(result) || std::isinf(result))
		std::cout << "Undefined";
	else std::cout << result;
	std::cout << std::endl << std::endl;
}

void printInvalidExpr()
{
	std::cout << "Invalid expression, "
		<< "please try again!"
		<< std::endl;
}

double processInput(std::string& userInput)
{
	try
	{
		Algebra alg;
		auto postfixExpr = alg.toPostfix(userInput);
		auto result = alg.evaluatePostfix(postfixExpr);
		return result;
	}
	catch (std::logic_error& ex)
	{
		printInvalidExpr();
		return NAN;
	}
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
		const auto result = processInput(userInput);
		printResult(result);
	}
	return 0;
}
