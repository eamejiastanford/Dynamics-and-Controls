// The main testing file

#include "pch.h"
#include <iostream>
#include <vector>

// Import libraries
#include "Symbol.h"
#include "Scalar.h"

using namespace std;

int main()
{

	// Initialize list of scalars
	Scalar x("x");
	Scalar y("y",20);
	Scalar z("z");

	// Initialize derivatives
	Scalar xp("x'"), xpp("x''");
	Scalar yp("y'"), ypp("y''");
	Scalar zp("z'"), zpp("z''");

	// Assign derivatives
	vector<Scalar *> derivs = { &xp, &xpp };
	x.setDerivatives(derivs);

	x = 13;
	
	// Print x
	x.printScalar();

	// Print xp
	xp.printScalar();

	y.printScalar();
	y = x + z;

	y.printScalar();
	z.printScalar();

	// Construct a symbolic ode
	int two = 2;
	int four = 4;
	zpp = toScalar(two) * x + toScalar(four) / yp - z * xpp;

	zpp.printScalar();

}

