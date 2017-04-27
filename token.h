#pragma once

#include <string>

using namespace std;

struct Token {
	int ln;			// line number
	string id;		// id based on grammar
	int ix;			// optional; index number
	string str;		// optional; actual string
};