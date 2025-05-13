/*
    Name: AlgebraDriver
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/12/2025
    Description: The C++ implementation file for the AlgebraDriver class.
*/

#include "Algebra.h"
#include <iostream>

void testEva(const std::string& expr)
{
	Algebra alg;
	auto postfix = alg.toPostfix(expr);
	std::cout << "Original Expression: " << expr << std::endl
		<< "Postfix Expression: " << postfix << std::endl;
	auto result = alg.evaluatePostfix(postfix);
	std::cout << "Result: " << result << std::endl
		<< std::endl;
}

void testConvert(const std::string& expr)
{
	Algebra alg;
	auto postfix = alg.toPostfix(expr);
	std::cout << "Original Expression: " << expr << std::endl
		<< "Postfix Expression: " << postfix << std::endl
		<< std::endl;
}

int main()
{
	testConvert("2 -3");
	testConvert("2 - 3");
	testConvert("2 - -3");
	testConvert("2 - (-3)");
	testEva("-15.1 + 16 * -8");
	testEva("15.1 + 16 * -8");
	testEva("(15 + 16) * -8");
	testEva("2 * (-3 + 4)");
	return 0;
}
