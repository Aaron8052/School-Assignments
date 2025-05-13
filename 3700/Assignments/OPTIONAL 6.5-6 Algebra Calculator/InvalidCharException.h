/*
    Name: InvalidCharException
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/13/2025
    Description: The C++ header file for the InvalidCharException class.
*/

#ifndef INVALIDCHAREXCEPTION_H
#define INVALIDCHAREXCEPTION_H
#include <stdexcept>

class InvalidCharException final : public std::logic_error
{
	public:
		InvalidCharException(const std::string& msg);
};

#endif //INVALIDCHAREXCEPTION_H
