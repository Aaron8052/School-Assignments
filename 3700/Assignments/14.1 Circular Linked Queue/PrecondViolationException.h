/*
    Name: PrecondViolationException
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/13/2025
    Description: The C++ header file
		for the PrecondViolationException class.
*/

#ifndef PRECONDVIOLATIONEXCEPTION_H
#define PRECONDVIOLATIONEXCEPTION_H
#include <stdexcept>

class PrecondViolationException final : public std::logic_error
{
	public:
		PrecondViolationException(const std::string& msg);
};

#endif //PRECONDVIOLATIONEXCEPTION_H
