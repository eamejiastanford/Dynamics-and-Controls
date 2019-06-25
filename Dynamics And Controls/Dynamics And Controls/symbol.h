#pragma once
#include "pch.h"
#include <string>

// Defines the symbol class object
// This is the basis for all symbolic objects in the dynamics & controls library

class Symbol
{
public:

	// The name of the symbol, for printing to the screen
	std::string name;

	// The right hand side of this symbol, for printing to the screen
	std::string rhs;

	// Prints the symbol as a string
	void printSymbol();

private:

};