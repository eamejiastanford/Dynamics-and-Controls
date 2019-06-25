#pragma once

// Defines the scalar class object
// A scalar is a real number with a sense of positive or negative

#include "Symbol.h"
#include <string>

// The scalar can be constant, variable, or specified with a function
enum scalarType { constant, variable, specified };

class Scalar
{
public:

	// The symbolic representation
	Symbol sym;

	// The numerical value
	float val;

	// The type of scalar
	scalarType type;

	// Prints a scalar (symbol and value)
	void printScalar();

	// Prints the value
	void printValue();

	// Assigns a name to a scalar
	void operator=(const std::string &name);

	// Assigns a value to a scalar
	void operator=(const float &val);

	// Assigs a right hand side to a scalar
	void operator=(const Scalar &b);

	// Adds two scalars (a + b)
	Scalar operator+(const Scalar &b) const;

	// Subracts two scalars (a - b)
	Scalar operator-(const Scalar &b) const;

	// Multiplies two scalars (a * b)
	Scalar operator*(const Scalar &b) const;

	// Divides two scalars (a / b)
	Scalar operator/(const Scalar &b) const;

private:

};