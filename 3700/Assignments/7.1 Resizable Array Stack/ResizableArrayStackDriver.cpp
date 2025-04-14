#include <iostream>
#include "MemoryAllocException.h"
int main()
{
	throw MemoryAllocException("Test");
	return 0;
}