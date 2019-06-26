#pragma once
#include "pch.h"

// Defines the scalar class object and helper subclasses
// A scalar is a real number with a sense of positive or negative

#include "Symbol.h"
#include <string>
#include <vector>

// The scalar can be constant, variable, or specified with a function
enum scalarType { constant, variable, specified };

// The right hand side of the scalar can be a primitive or an operator (+, -, *, /)
enum rhsType { primitive, addition, subtraction, multiplication, division };

class Scalar;

// Defines the RHS of a scalar
class RightHandSide
{
public:

	// The symbolic representation of the RHS
	Symbol sym;

	// The type of RHS, defined above
	rhsType type;

	// The operands
	RightHandSide *a;
	RightHandSide *b;

	// Primitive scalar
	Scalar *prim;

	// Evaluates the right hand side
	float eval();

private:

};

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

	// The right hand side of the scalar
	RightHandSide rhs;

	// Flag to check if the scalar has a rhs
	bool hasRHS;

	// Prints a scalar (symbol and value)
	void printScalar();

	// Default constructor
	Scalar() { hasDeriv = false; hasVal = false; hasRHS = false; };

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
	void operator=(const RightHandSide &b);

	// Adds two scalars (a + b)
	RightHandSide operator+(Scalar &b);
	RightHandSide operator+(RightHandSide &b);
	RightHandSide operator+(const float &b);

	// Subracts two scalars (a - b)
	RightHandSide operator-(Scalar &b);
	RightHandSide operator-(RightHandSide &b);
	RightHandSide operator-(const float &b);

	// Multiplies two scalars (a * b)
	RightHandSide operator*(Scalar &b);
	RightHandSide operator*(RightHandSide &b);
	RightHandSide operator*(const float &b);

	// Divides two scalars (a / b)
	RightHandSide operator/(Scalar &b);
	RightHandSide operator/(RightHandSide &b);
	RightHandSide operator/(const float &b);

	// Assigns derivative links
	void setDerivatives(std::vector<Scalar *> derivs);

	// Updates the scalar
	void updateScalar();

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

// Converts a scalar to a primitive RHS
RightHandSide *toRHS(Scalar * b);
