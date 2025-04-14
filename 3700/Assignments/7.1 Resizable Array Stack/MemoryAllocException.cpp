/*
    Name: MemoryAllocException
    Copyright: 2025
    Author: Yu Jiang
    Date: 4/13/25
    Description: The C++ implementation file for the MemoryAllocException class.
*/

#include "MemoryAllocException.h"

MemoryAllocException::MemoryAllocException(const std::string& msg)
	: logic_error("Memory Allocation Exception: " + msg)
{}
