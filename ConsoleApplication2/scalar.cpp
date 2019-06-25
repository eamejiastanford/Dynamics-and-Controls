#include "pch.h"

#include "scalar.h"
#include <iostream>
#include <string>

void Scalar::printScalar()
{
	if (sym.name == sym.rhs) {
		std::cout << sym.name << " has value " << val << std::endl;
	}
	else {
		std::cout << sym.name << " = " << sym.rhs << " has value " << val << std::endl;
	}
}

void Scalar::printValue()
{
	std::cout << val << std::endl;
}

void Scalar::operator=(const std::string & newName)
{
	// Set name and default RHS to identity
	sym.name = newName;
	sym.rhs = newName;
}

void Scalar::operator=(const float & newValue)
{
	// Reassign the value and reset RHS to identity
	val = newValue;
	sym.rhs = sym.name;
}

void Scalar::operator=(const Scalar & b)
{
	// Set symbolic RHS
	sym.rhs = b.sym.name;

	// Reassign value
	val = b.val;

}

Scalar Scalar::operator+(const Scalar & b) const
{
	// Construct a new scalar to return
	Scalar c;

	// Add the symbols and the values
	c.sym.name = sym.name + " + " + b.sym.name;
	c.val = val + b.val;

	// Add the values
	return c;
}

Scalar Scalar::operator-(const Scalar & b) const
{
	// Construct a new scalar to return
	Scalar c;

	// Add the symbols and the values
	c.sym.name = sym.name + " - " + b.sym.name;
	c.val = val - b.val;

	// Add the values
	return c;
}

Scalar Scalar::operator*(const Scalar & b) const
{
	// Construct a new scalar to return
	Scalar c;

	// Add the symbols and the values
	c.sym.name = sym.name + " * " + b.sym.name;
	c.val = val * b.val;

	// Add the values
	return c;
}

Scalar Scalar::operator/(const Scalar & b) const
{
	// Construct a new scalar to return
	Scalar c;

	// Add the symbols and the values
	c.sym.name = sym.name + " / " + b.sym.name;
	c.val = val / b.val;

	// Add the values
	return c;
}
