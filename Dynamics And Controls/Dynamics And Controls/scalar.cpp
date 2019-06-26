#include "pch.h"

#include "scalar.h"
#include <iostream>

void Scalar::printScalar()
{
	// Update the scalar
	updateScalar();

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
	if (hasRHS) {
		rhs.sym.name = cleanName(rhs.sym.name);
		std::cout << " = " << rhs.sym.name;
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
	// Set name, reset value
	sym.name = newName;
	hasVal = false;
}

void Scalar::operator=(const float & newValue)
{
	// Reassign the value
	hasVal = true;
	val = newValue;
}

void Scalar::operator=(const RightHandSide & b)
{
	// Assign the RHS to the scalar
	hasRHS = true;
	rhs = b;
}

RightHandSide Scalar::operator+(Scalar & b)
{
	// Construct a new RHS to return
	RightHandSide *c = new RightHandSide;

	// Add the symbols
	c->sym.name = "(" + sym.name + " + " + b.sym.name + ")";

	// Assign the RHS operands and operation
	c->a = toRHS(this);
	c->b = toRHS(&b);
	c->type = addition;

	return *c;
}

RightHandSide Scalar::operator+(RightHandSide & b)
{
	// Construct a new RHS to return
	RightHandSide *c = new RightHandSide;

	// Add the symbols
	c->sym.name = "(" + sym.name + " + " + b.sym.name + ")";

	// Assign the RHS operands and operation
	c->a = toRHS(this);
	c->b = &b;
	c->type = addition;

	return *c;
}

RightHandSide Scalar::operator+(const float & b)
{
	// Convert float to scalar and then operate
	Scalar bScalar = toScalar(b);
	return bScalar + *this;
}

RightHandSide Scalar::operator-(Scalar & b)
{
	// Construct a new RHS to return
	RightHandSide c;

	// Add the symbols
	c.sym.name = "(" + sym.name + " - " + b.sym.name + ")";

	// Assign the RHS operands and operation
	c.a = toRHS(this);
	c.b = toRHS(&b);
	c.type = subtraction;

	return c;
}

RightHandSide Scalar::operator-(RightHandSide & b)
{
	// Construct a new RHS to return
	RightHandSide c;

	// Add the symbols
	c.sym.name = "(" + sym.name + " - " + b.sym.name + ")";

	// Assign the RHS operands and operation
	c.a = toRHS(this);
	c.b = &b;
	c.type = subtraction;

	return c;
}

RightHandSide Scalar::operator-(const float & b)
{
	// Convert float to scalar and then operate
	Scalar bScalar = toScalar(b);
	return bScalar - *this;
}

RightHandSide Scalar::operator*(Scalar & b)
{
	// Construct a new RHS to return
	RightHandSide c;

	// Add the symbols
	c.sym.name = "(" + sym.name + " * " + b.sym.name + ")";

	// Assign the RHS operands and operation
	c.a = toRHS(this);
	c.b = toRHS(&b);
	c.type = multiplication;

	return c;
}

RightHandSide Scalar::operator*(RightHandSide & b)
{
	// Construct a new RHS to return
	RightHandSide c;

	// Add the symbols
	c.sym.name = "(" + sym.name + " * " + b.sym.name + ")";

	// Assign the RHS operands and operation
	c.a = toRHS(this);
	c.b = &b;
	c.type = multiplication;

	return c;
}

RightHandSide Scalar::operator*(const float & b)
{
	// Convert float to scalar and then operate
	Scalar bScalar = toScalar(b);
	return bScalar * *this;
}

RightHandSide Scalar::operator/(Scalar & b)
{
	// Construct a new RHS to return
	RightHandSide c;

	// Add the symbols
	c.sym.name = "(" + sym.name + " / " + b.sym.name + ")";

	// Assign the RHS operands and operation
	c.a = toRHS(this);
	c.b = toRHS(&b);
	c.type = division;

	return c;
}

RightHandSide Scalar::operator/(RightHandSide & b)
{
	// Construct a new RHS to return
	RightHandSide c;

	// Add the symbols
	c.sym.name = "(" + sym.name + " / " + b.sym.name + ")";

	// Assign the RHS operands and operation
	c.a = toRHS(this);
	c.b = &b;
	c.type = division;

	return c;
}

RightHandSide Scalar::operator/(const float & b)
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
}

void Scalar::updateScalar()
{
	if (hasRHS) {
		rhs.sym.name = cleanName(rhs.sym.name);
		val = rhs.eval();
		hasVal = true;
	}

}

Scalar toScalar(const float & b)
{
	Scalar *bScalar = new Scalar(std::to_string(b));
	*bScalar = b;
	return *bScalar;
}

RightHandSide *toRHS(Scalar * b)
{
	// Construct new RHS
	RightHandSide *c = new RightHandSide;

	// Assign the scalar to the primitive RHS
	c->type = primitive;
	c->prim = b;
	c->sym = b->sym;

	return c;
}

float RightHandSide::eval()
{
	std::cout << sym.name << ", " << type << std::endl;

	switch (type) {
	case primitive: return prim->val; // base case
		break;
	case addition: return a->eval() + b->eval();
		break;
	case subtraction: return a->eval() - b->eval();
		break;
	case multiplication: return a->eval() * b->eval();
		break;
	case division: return a->eval() / b->eval();
	}
	return 0.0f;
}