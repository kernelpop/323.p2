//	Team ID:			DDM
//	Daniel Bravo		bravod@csu.fullerton.edu
//	David Feinzimer		dfeinzimer@csu.fullerton.edu
//	Mircea Dumitrache	dmircea@csu.fullerton.edu
//	Description:		Contains the declaration of token, conversion functions and our printing function.

#pragma once

#ifndef resources_h
#define resources_h

#endif /* Header_h */

#include <fstream>
#include <string>
#include <vector>


using namespace std;

//	========  Global Variables  ========
const int KEY_WORD_SIZE = 13;
string keyWord[KEY_WORD_SIZE] = { "prog", "main", "fcn", "class",
"float", "int", "string", "if",
"elseif", "else", "while", "input",
"print" };

//	========  Function Prototypes  ========
void printer();						//	Prints all accumulated and formatted tokens
string txt_to_strings();			//	Converts a text file to a vector of strings
void print_tokens(vector<Token> &t);
void tokenize(string s);            // a function to derive tokens from a string
Token tokenate();                   // takes current variables to create a token
Token peek_token();
Token next_token();

