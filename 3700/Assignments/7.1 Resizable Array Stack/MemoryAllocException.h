/*
    Name: MemoryAllocException
    Copyright: 2025
    Author: Yu Jiang
    Date: 4/13/25
    Description: The C++ header file for the MemoryAllocException class.
*/

#ifndef MEMORYALLOCEXCEPTION_H
#define MEMORYALLOCEXCEPTION_H

#include <stdexcept>
#include <string>

class MemoryAllocException final : public std::logic_error
{
	public:
		explicit MemoryAllocException(const std::string& msg = "");
};

#include "MemoryAllocException.cpp"
#endif //MEMORYALLOCEXCEPTION_H
