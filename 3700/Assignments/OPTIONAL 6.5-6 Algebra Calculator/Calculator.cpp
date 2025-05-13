/*
    Name: Calculator
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/12/2025
    Description: The C++ implementation file for the Calculator class.
*/

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
			<< "enter \"" << EXIT << "\" to quit"
			<< std::endl << "Expression: ";
		std::getline(std::cin, userInput);
		std::cin.clear();
		if (userInput == EXIT)
			break;
		auto postfixExpr = alg.toPostfix(userInput);
		std::cout << "Postfix Expression: " << postfixExpr
			<< std::endl;
		auto result = alg.evaluatePostfix(postfixExpr);
		std::cout << "Result: " << result << std::endl
			<< std::endl;
	}
	return 0;
}
