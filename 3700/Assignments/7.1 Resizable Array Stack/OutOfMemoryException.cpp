/*
    Name: MemoryAllocException
    Copyright: 2025
    Author: Yu Jiang
    Date: 4/13/25
    Description: The C++ implementation file for the OutOfMemoryException class.
*/

#include "OutOfMemoryException.h"

OutOfMemoryException::OutOfMemoryException(const std::string& msg)
	: logic_error("OutOfMemoryException: " + msg)
{}
