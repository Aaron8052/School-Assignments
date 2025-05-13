/*
    Name: Algebra
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/12/2025
    Description: The C++ implementation file for the Algebra class.
*/

#include "Algebra.h"
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
		|| c == '.';
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

// End Private

std::string Algebra::toPostfix(const std::string& infixExp)
{
	std::string postfixExp = "";
	ArrayStack<char> operators(10);

	// Record if the previous char is an operator
	bool isPrevOperator = true;
	// foreach char in infix expression
	for (char c : infixExp)
	{
		if (isOperand(c))
		{
			if (isPrevOperator)
				postfixExp.push_back(SEPARATOR);
			isPrevOperator = false;
			postfixExp.push_back(c);
		}
		else if (c == '(')
		{
			isPrevOperator = true;
			operators.push(c);
		}
		else if (isOperator(c))
		{
			// Negative sign
			if (c == '-' && isPrevOperator)
			{
				isPrevOperator = false;
				postfixExp.push_back(SEPARATOR);
				postfixExp.push_back(c);
				continue;
			}
			isPrevOperator = true;
			while (!operators.isEmpty()
				&& operators.peek() != '('
				&& getPrecedenceOf(c) <= getPrecedenceOf(operators.peek()))
			{
				postfixExp.push_back(SEPARATOR);
				postfixExp.push_back(operators.peek());
				operators.pop();
			}
			operators.push(c);
		}
		else if (c == ')')
		{
			isPrevOperator = true;
			while (operators.peek() != '(')
			{
				postfixExp.push_back(SEPARATOR);
				postfixExp.push_back(operators.peek());
				operators.pop();
			}
			operators.pop();
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

float Algebra::evaluatePostfix(std::string postfixExp)
{
	return 0;
}
