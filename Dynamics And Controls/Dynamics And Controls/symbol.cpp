#include "pch.h"

#include "Symbol.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void Symbol::printSymbol()
{
	std::cout << name << std::endl;
}

enum operatorPriority { subtraction, addition, division, multiplication, none };

std::string cleanName(std::string name) {

	// Indices for parentheses
	std::vector<int> start = {};
	std::vector<int> finish = {};

	// Priority value of operators
	int L = none;
	int R = none;

	// Find the parens
	findParens(name, start, finish);

	// Go through each pair and determine redundancy
	for (int i = 0; i < start.size(); i++) {

		// Find left operator
		L = findLeftOperator(name, start[i]);

		// Find right operator
		R = findRightOperator(name, finish[i]);

		// Check for no operators
		if (L == none && R == none) {

			// Remove redundant parens
			removeParens(name, start, finish, i);
		}
		else {

			// Find lowest priority operator inside parens
			int X = findLowestOperator(name, start[i], finish[i]);

			// Check for lower proirity inside operator
			if ( (X < L && L != none) || (X < R && R != none) ) {
				// Not redundant, continue
			}
			else {
				// Remove redundant parens
				removeParens(name, start, finish, i);
			}

		}
	}

	return name;

}

void removeParens(std::string &name, std::vector<int> &start, std::vector<int> &finish, int i) {
	name.erase(finish[i], 1);
	name.erase(start[i], 1);
	for (int j = i + 1; j < start.size(); j++) {
		if (start[j] > start[i]) {
			start[j]--;
			finish[j]--;
		}
		if (finish[j] > finish[i]) {
			start[j]--;
			finish[j]--;
		}

	}
}

int findLeftOperator(std::string & name, int start)
{
	// Initialize operator priority value
	int L = none;

	// Sarch backwards in string for first operator
	int idx = start;
	while (idx >= 0 && L == none) {
		char c = name[idx];
		if (c == '*') {
			L = multiplication;
		}
		else if (c == '/') {
			L = division;
		}
		else if (c == '+') {
			L = addition;
		}
		else if (c == '-') {
			L = subtraction;
		}
		idx--;
	}

	return L;
}

int findRightOperator(std::string & name, int finish)
{

	// Initialize operator priority value
	int R = none;

	// Sarch forwards in string for first operator
	int idx = finish;
	while (idx < name.size() && R == none) {
		char c = name[idx];
		if (c == '*') {
			R = multiplication;
		}
		else if (c == '/') {
			R = division;
		}
		else if (c == '+') {
			R = addition;
		}
		else if (c == '-') {
			R = subtraction;
		}
		idx++;
	}

	return R;

}

int findLowestOperator(std::string & name, int start, int finish)
{
	// Initialize operator priority value
	int X = none;

	// Search forwards in string for lowest operator priority
	int idx = start;
	int parenLevel = 0;
	while (idx <= finish) {
		char c = name[idx];
		if (c == '*' && parenLevel == 1) {
			X = std::min(X, (int)multiplication);
		}
		else if (c == '/' && parenLevel == 1) {
			X = std::min(X, (int)division);
		}
		else if (c == '+' && parenLevel == 1) {
			X = std::min(X, (int)addition);
		}
		else if (c == '-' && parenLevel == 1) {
			X = std::min(X, (int)subtraction);
			return X; // Can't get lower level than subtraction
		} else if (c == '(') {
			parenLevel++;
		} else if (c == ')') {
			parenLevel--;
		}
		idx++;
	}
	return X;
}

void findParens(std::string name, std::vector<int> &start, std::vector<int> &finish) {

	for (int i = 0; i < name.length(); i++) {

		// Get the character
		char c = name[i];

		// Note the indices of the parens
		if (c == '(') {
			start.push_back(i);
			finish.push_back(-1); // Placeholder
		}
		else if (c == ')') {
			int idx = finish.size() - 1;
			while (idx >= 0 && finish[idx] != -1) { idx--; }; // Search for most recent placeholder
			finish[idx] = i;
		}
	}
}
