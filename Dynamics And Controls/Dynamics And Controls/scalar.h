#pragma once
#include "pch.h"

// Defines the scalar class object
// A scalar is a real number with a sense of positive or negative

#include "Symbol.h"
#include <string>
#include <vector>

// The scalar can be constant, variable, or specified with a function
enum scalarType { constant, variable, specified };

class Scalar
{
public:

	// The symbolic representation
	Symbol sym;

	// Bool to check if the scalar has a value
	bool hasVal;

	// The numerical value
	float val;

	// The type of scalar
	scalarType type;

	// Flag to check if the scalar has a derivative
	bool hasDeriv;

	// Link to the derivative of the scalar with respect to time
	Scalar *deriv;

	// Prints a scalar (symbol and value)
	void printScalar();

	// Default constructor
	Scalar() { hasDeriv = false; hasVal = false; };

	// Constructor with a name
	Scalar(const std::string &name) { *this = name; };

	// Constructor with a value
	Scalar(const float &value) { *this = value; };

	// Constructor with a name and value
	Scalar(const std::string &name, const float &value) { *this = name; *this = value; };

	// Assigns a name to a scalar
	void operator=(const std::string &name);

	// Assigns a value to a scalar
	void operator=(const float &val);

	// Assigs a right hand side to a scalar
	void operator=(const Scalar &b);

	// Adds two scalars (a + b)
	Scalar operator+(const Scalar &b) const;
	Scalar operator+(const float &b) const;

	// Subracts two scalars (a - b)
	Scalar operator-(const Scalar &b) const;
	Scalar operator-(const float &b) const;

	// Multiplies two scalars (a * b)
	Scalar operator*(const Scalar &b) const;
	Scalar operator*(const float &b) const;

	// Divides two scalars (a / b)
	Scalar operator/(const Scalar &b) const;
	Scalar operator/(const float &b) const;

	// Assigns derivative links
	void setDerivatives(std::vector<Scalar *> derivs);

private:

	// Prints the value
	void printValue();

	// Prints the right hand side
	void printRHS();

	// Prints the derivatives
	void printDerivs();

	// Recursive helper for derivatives printer
	void printDerivsHelper();

};

// Converts a float to a scalar
Scalar toScalar(const float &b);
