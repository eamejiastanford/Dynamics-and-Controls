#pragma once

// Defines a workspace object where all variables live

#include <set>

#include "scalar.h"

class Workspace
{
public : 

	// The set of all scalars
	ScalarWorkspace scalarSet;

private : 

};

class ScalarWorkspace
{
public :

	// The set of all constant scalars
	std::set<Scalar *> constantScalars;

	// The set of all variable scalars
	std::set<Scalar *> variableScalars;

	// The set of all specified scalars
	std::set<Scalar *> specifiedScalars;

private :

};