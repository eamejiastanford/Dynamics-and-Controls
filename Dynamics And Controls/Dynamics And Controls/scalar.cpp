#include "pch.h"

#include "scalar.h"
#include <iostream>

void Scalar::printScalar()
{
	// Print the name
	std::cout << sym.name;

	// Print right hand side, if not identity
	printRHS();

	// Print value, if any
	printValue();

	// Print derivatives, if any
	printDerivs();

	// End the line
	std::cout << std::endl;
}

void Scalar::printValue()
{
	if (hasVal) {
		std::cout << " has value " << val;
	}
}

void Scalar::printRHS()
{
	if (sym.name != sym.rhs) {
		std::cout << " = " << sym.rhs;
	}
}

void Scalar::printDerivs()
{
	if (hasDeriv && hasVal) {
		std::cout << " and derivatives " << deriv->sym.name;
		deriv->printDerivsHelper();
	}
	else if (hasDeriv) {
		std::cout << " has derivatives " << deriv->sym.name;
		deriv->printDerivsHelper();
	}
}

void Scalar::printDerivsHelper()
{
	if (hasDeriv) {
		std::cout << ", " << deriv->sym.name;
		deriv->printDerivsHelper();
	}
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
	hasVal = true;
	val = newValue;
	sym.rhs = sym.name;
}

void Scalar::operator=(const Scalar & b)
{
	// Set symbolic RHS
	sym.rhs = b.sym.name;

	// Reassign value, if necessary
	if (b.hasVal) {
		val = b.val;
	}

}

Scalar Scalar::operator+(const Scalar & b) const
{
	// Construct a new scalar to return
	Scalar c;

	// Add the symbols
	c.sym.name = sym.name + " + " + b.sym.name;

	// Add the values, if possible
	if (hasVal && b.hasVal) {
		c.val = val + b.val;
	}

	// Add the values
	return c;
}

Scalar Scalar::operator+(const float & b) const
{
	// Convert float to scalar and then operate
	Scalar bScalar = toScalar(b);
	return bScalar + *this;
}

Scalar Scalar::operator-(const Scalar & b) const
{
	// Construct a new scalar to return
	Scalar c;

	// Subtract the symbols
	c.sym.name = sym.name + " - " + b.sym.name;

	// Subtract the values, if possible
	if (hasVal && b.hasVal) {
		c.val = val - b.val;
	}

	// Add the values
	return c;
}

Scalar Scalar::operator-(const float & b) const
{
	// Convert float to scalar and then operate
	Scalar bScalar = toScalar(b);
	return bScalar - *this;
}

Scalar Scalar::operator*(const Scalar & b) const
{
	// Construct a new scalar to return
	Scalar c;

	// Multiply the symbols and the values
	c.sym.name = sym.name + " * " + b.sym.name;

	// Multiply the values, if possible
	if (hasVal && b.hasVal) {
		c.val = val * b.val;
	}

	// Add the values
	return c;
}

Scalar Scalar::operator*(const float & b) const
{
	// Convert float to scalar and then operate
	Scalar bScalar = toScalar(b);
	return bScalar * *this;
}

Scalar Scalar::operator/(const Scalar & b) const
{
	// Construct a new scalar to return
	Scalar c;

	// Divide the symbols
	c.sym.name = sym.name + " / " + b.sym.name;

	// Divide the values, if possible
	if (hasVal && b.hasVal) {
		c.val = val / b.val;
	}

	// Add the values
	return c;
}

Scalar Scalar::operator/(const float & b) const
{
	// Convert float to scalar and then operate
	Scalar bScalar = toScalar(b);
	return bScalar / *this;
}

void Scalar::setDerivatives(std::vector<Scalar *> derivs)
{

	// Loop through list of derivatives, assigning each in order
	Scalar *currentScalar = this;
	for (int i = 0; i < derivs.size(); i++) {
		
		// Assign the derivative to this scalar
		currentScalar->deriv = derivs[i];
		currentScalar->hasDeriv = true;

		// Move on to next scalar
		currentScalar = derivs[i];
	}






	//// Assign the derivative of this symbol
	//deriv = derivs[0];
	//hasDeriv = true;

	//// Recursively assign derivatives to next symbol
	//if ( derivs.size() > 1) {
	//	std::vector<Scalar *> nextDerivs
	//	derivs[0]->setDerivatives(derivs);
	//}
}

Scalar toScalar(const float & b)
{
	Scalar bScalar(std::to_string(b));
	bScalar = b;
	return bScalar;
}
