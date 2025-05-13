/*
    Name: InvalidCharException
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/13/2025
    Description: The C++ implementation file
        for the InvalidCharException class.
*/

#include "InvalidCharException.h"

InvalidCharException::
InvalidCharException(const std::string& msg)
	: logic_error("Invalid Character Exception: " + msg)
{}
