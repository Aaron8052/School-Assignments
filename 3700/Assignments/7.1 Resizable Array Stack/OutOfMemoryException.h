/*
    Name: MemoryAllocException
    Copyright: 2025
    Author: Yu Jiang
    Date: 4/13/25
    Description: The C++ header file for the OutOfMemoryException class.
*/

#ifndef MEMORYALLOCEXCEPTION_H
#define MEMORYALLOCEXCEPTION_H

#include <stdexcept>
#include <string>

class OutOfMemoryException final : public std::logic_error
{
	public:
		OutOfMemoryException(const std::string& msg = "");
};

#endif //MEMORYALLOCEXCEPTION_H
