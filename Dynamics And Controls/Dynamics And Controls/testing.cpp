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

	// Construct a symbolic ode
	int two = 2;
	int four = 4;
	yp = 12;
	z = -2;
	xpp = 2;
	//zpp = toScalar(two) * x + toScalar(four) / (yp + z * xpp);
	zpp = z * xpp;

	zpp.printScalar();

	xpp = 5;
	xpp.printScalar();
	zpp.printScalar();
}

