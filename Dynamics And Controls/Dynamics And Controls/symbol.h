#pragma once
#include "pch.h"
#include <string>
#include <vector>

// Defines the symbol class object
// This is the basis for all symbolic objects in the dynamics & controls library

class Symbol
{
public:

	// The name of the symbol, for printing to the screen
	std::string name;

	// Prints the symbol as a string
	void printSymbol();

private:

};

// Cleans up a symbol's name
std::string cleanName(std::string name);

// Finds the parenthesis pairs in a string
void findParens(std::string name, std::vector<int> &start, std::vector<int> &end);

// Removes redundant parenthesis pair from a string
void removeParens(std::string &name, std::vector<int> &start, std::vector<int> &finish, int i);

// Finds the operator closest to the left parenthesis
int findLeftOperator(std::string &name, int start);

// Removes redundant parenthesis pair from a string
int findRightOperator(std::string &name, int finish);

// Removes redundant parenthesis pair from a string
int findLowestOperator(std::string &name, int start, int finish);
