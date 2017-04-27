#pragma once

#include <string>
#include <vector>
#include "token.h"
#include <iostream>

using namespace std;

void token_printer(string _Language, vector<Token> &tokens) { // Prints out all tokens

	cout << "(:lang " << _Language << endl;	//	Print the language

	for (size_t i = 0; i < tokens.size(); i++) {	// For each token in our tokens vector

		for (int i = 0; i < 3; i++) { // Indent the new line
			cout << " ";
		}

		cout << "(:token " << tokens[i].ln << " " << tokens[i].id;	//	Print line number

		if (tokens[i].id == "ident") {	//	If the token has an index, print it
			cout << " :ix " << tokens[i].ix;
		}

		if (tokens[i].id == "ident" |
			tokens[i].id == "string" |
			tokens[i].id == "int" |
			tokens[i].id == "float") {
			cout << " :str \"" << tokens[i].str << "\"";	//	If the token has a str, print it
		}

		cout << ")" << endl;	//	Finish printing that token
	}

	cout << ")" << endl;	//	Finish the print function
	tokens.clear();
}