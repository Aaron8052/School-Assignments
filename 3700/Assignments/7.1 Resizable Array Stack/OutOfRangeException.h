/*
    Name: OutOfRangeException
    Copyright: 2025
    Author: Yu Jiang
    Date: 04/14/2025
    Description: The C++ header file for the OutOfRangeException class.
*/

#ifndef OUTOFRANGEEXCEPTION_H
#define OUTOFRANGEEXCEPTION_H

#include <stdexcept>
#include <string>

class OutOfRangeException final : public std::out_of_range
{
	public:
		explicit OutOfRangeException(const std::string& msg = "");
};

#endif //OUTOFRANGEEXCEPTION_H
