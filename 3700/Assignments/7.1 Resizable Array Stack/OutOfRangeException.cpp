/*
    Name: OutOfRangeException
    Copyright: 2025
    Author: Yu Jiang
    Date: 04/14/2025
    Description: The C++ implementation file for the OutOfRangeException class.
*/

#include "OutOfRangeException.h"

OutOfRangeException::OutOfRangeException(const std::string& msg)
	: out_of_range("Stack OutOfRangeException: " + msg)
{}
