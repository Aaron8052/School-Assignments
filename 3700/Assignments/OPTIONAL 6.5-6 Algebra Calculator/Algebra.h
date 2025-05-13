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
        const char SEPARATOR = ' ';
        static bool isOperand(char c);
        static bool isOperator(char c);
        static int getPrecedenceOf(char c);
    public:
        std::string toPostfix(const std::string& infixExp);
        float evaluatePostfix(std::string postfixExp);
};

#endif //ALGEBRA_H
