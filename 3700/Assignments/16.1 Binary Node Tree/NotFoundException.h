//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#ifndef NOT_FOUND_EXCEPTION_
#define NOT_FOUND_EXCEPTION_

#include <stdexcept>
#include <string>
class NotFoundException: public std::logic_error
{
	public :
		NotFoundException(const std::string& message = "")
			: std::logic_error("Target not found: " + message)
		{
		} // end constructor
}; // end TargetNotFoundException

#endif
