#pragma once

#include <iostream>
#include <list>
#include <string>
#include "token.h"

using namespace std;

class symbol {
	string name;
	bool isTerminal;
public:
	symbol() {}
	symbol(string rName, bool rIsTerminal) {
		name = rName;
		isTerminal = rIsTerminal;
	}
	~symbol();
};
