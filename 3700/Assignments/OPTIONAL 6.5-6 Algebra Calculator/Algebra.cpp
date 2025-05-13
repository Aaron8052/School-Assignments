/*
    Name: Algebra
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/12/2025
    Description: The C++ implementation file for the Algebra class.
*/

#include "Algebra.h"
#include <math.h>
#include "ArrayStack.h"

// Private

bool Algebra::isOperand(const char c)
{
	return c == '0'
		|| c == '1'
		|| c == '2'
		|| c == '3'
		|| c == '4'
		|| c == '5'
		|| c == '6'
		|| c == '7'
		|| c == '8'
		|| c == '9'
		|| c == '.'
		|| c == NEGATIVE_SIGN;
}

bool Algebra::isOperator(const char c)
{
	return c == '+'
		|| c == '-'
		|| c == '*'
		|| c == '/';
}

int Algebra::getPrecedenceOf(const char c)
{
	return (c == '*' || c == '/') ? 1 : 0;
}

double Algebra::calOperands(char op, double opnd1, double opnd2)
{
	if (op == '*')
		return opnd1 * opnd2;
	if (op == '/')
		return opnd1 / opnd2;
	if (op == '+')
		return opnd1 + opnd2;
	if (op == '-')
		return opnd1 - opnd2;
	return 0;
}

// End Private

std::string Algebra::toPostfix(const std::string& infixExp)
{
	std::string postfixExp = "";
	ArrayStack<char> operators(10);
	// Record if the previous char was an operator
	bool prevWasOperator = true;
	// foreach char in infixExp
	for (char c : infixExp)
	{
		if (isOperand(c))
		{
			if (prevWasOperator && !postfixExp.empty())
				postfixExp.push_back(SEPARATOR);
			postfixExp.push_back(c);
			prevWasOperator = false;
		}
		else if (c == '(')
		{
			operators.push(c);
			prevWasOperator = true;
		}
		else if (isOperator(c))
		{
			// Negative sign
			if (c == '-' && prevWasOperator)
			{
				if (!postfixExp.empty())
					postfixExp.push_back(SEPARATOR);
				postfixExp.push_back(NEGATIVE_SIGN);
				prevWasOperator = false;
				continue;
			}
			// Positive sign
			if (c == '+' && prevWasOperator)
			{
				// ignore positive sign
				continue;
			}
			while (!operators.isEmpty()
				&& operators.peek() != '('
				&& getPrecedenceOf(c) <= getPrecedenceOf(operators.peek()))
			{
				if (!postfixExp.empty())
					postfixExp.push_back(SEPARATOR);
				postfixExp.push_back(operators.peek());
				operators.pop();
			}
			operators.push(c);
			prevWasOperator = true;
		}
		else if (c == ')')
		{
			while (operators.peek() != '(')
			{
				if (!postfixExp.empty())
					postfixExp.push_back(SEPARATOR);
				postfixExp.push_back(operators.peek());
				operators.pop();
			}
			operators.pop();
			prevWasOperator = true;
		}
	}
	while (!operators.isEmpty())
	{
		postfixExp.push_back(SEPARATOR);
		postfixExp.push_back(operators.peek());
		operators.pop();
	}
	return postfixExp;
}

double Algebra::
evaluatePostfix(const std::string& postfixExp)
{
	ArrayStack<double> operands(10);
	// temporarily store the number for later parsing
	std::string operandBuffer = "";
	// foreach char in postfixExp
	for (char c : postfixExp)
	{
		// Each element ends with SEPARATOR,
		// if buffer is not empty then this the end of a number
		if (c == SEPARATOR && !operandBuffer.empty())
		{
			// Parse the num in buffer, and push to the stack
			operands.push(std::stod(operandBuffer));
			operandBuffer.clear();
			continue;
		}
		if (isOperand(c))
		{
			// Store the digit of num into temp buffer
			// Convert NEGATIVE_SIGN back to normal "-"
			if (c == NEGATIVE_SIGN)
				operandBuffer.push_back('-');
			else operandBuffer.push_back(c);
			continue;
		}
		if (!isOperator(c)) continue;
		auto operand2 = operands.peek();
		operands.pop();
		auto operand1 = operands.peek();
		operands.pop();
		auto result = calOperands(c, operand1, operand2);
		operands.push(result);
	}
	if (!operandBuffer.empty())
	{
		// Parse the num in buffer, and push to the stack
		operands.push(std::stod(operandBuffer));
		operandBuffer.clear();
	}
	return operands.isEmpty() ? NAN : operands.peek();
}
