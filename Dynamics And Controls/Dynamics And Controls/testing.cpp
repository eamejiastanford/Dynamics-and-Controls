// The main testing file

#include "pch.h"
#include <iostream>

// Import libraries
#include "Symbol.h"
#include "Scalar.h"

int main()
{

	// Initialize list of scalars
	Scalar x("x");
	Scalar y("y",20);
	Scalar z("z");

	x = 13;
	
	// Print both variables
	x.printScalar();
	y.printScalar();

	// Set RHS of y
	y = x;

	// Reprint y
	y.printScalar();

	// Reset y
	y = 45;
	y.printScalar();

	// Compute z
	z = "z";
	z = x + y;
	z.printScalar();

	// Compute z
	z = "z";
	z = x - y;
	z.printScalar();

	// Compute z
	z = "z";
	z = x * y;
	z.printScalar();

	// Compute z
	z = "z";
	z = x / y;
	z.printScalar();

}

