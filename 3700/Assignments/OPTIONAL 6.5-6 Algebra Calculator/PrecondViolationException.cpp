/*
    Name: PrecondViolationException
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/13/2025
    Description: The C++ implementation file for the PrecondViolationException class.
*/

#include "PrecondViolationException.h"

PrecondViolationException::PrecondViolationException(const std::string& msg)
            : logic_error("Precondition Violation Exception: " + msg) {}
