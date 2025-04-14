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

using namespace std;

class MemoryAllocException final : public logic_error
{
	public:
		explicit MemoryAllocException(const string& msg = "");
};

#endif //MEMORYALLOCEXCEPTION_H
