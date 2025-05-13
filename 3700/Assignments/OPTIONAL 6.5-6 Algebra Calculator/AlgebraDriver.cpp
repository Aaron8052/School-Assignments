/*
    Name: AlgebraDriver
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/12/2025
    Description: The C++ implementation file for the AlgebraDriver class.
*/

#include "Algebra.h"
#include <iostream>
void testConversion(std::string expr)
{
    Algebra alg;
    std::cout << "Original Expression: "
        << expr << std::endl
        << "Postfix Expression: "
        << alg.toPostfix(expr) << std::endl
        << std::endl;
}

int main()
{
    testConversion("-15.1 + 16 * -8");
    testConversion("15.1 + 16 * -8");
    testConversion("(15 + 16) * -8");
    testConversion("2 * (-3 + 4)");
    return 0;
}