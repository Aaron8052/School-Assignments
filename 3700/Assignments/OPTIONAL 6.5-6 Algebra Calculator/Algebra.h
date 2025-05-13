/*
    Name: Algebra
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/12/2025
    Description: The C++ header file for the Algebra class.
*/

#ifndef ALGEBRA_H
#define ALGEBRA_H
#include <string>

class Algebra
{
	private:
		static const char NEGATIVE_SIGN = '~';
		static const char SEPARATOR = ' ';
		static bool isOperand(char c);
		static bool isOperator(char c);
		static int getPrecedenceOf(char c);
		static double calOperands(char op, double opnd1, double opnd2);

	public:
		std::string toPostfix(const std::string& infixExp);
		double evaluatePostfix(const std::string& postfixExp);
};

#endif //ALGEBRA_H
