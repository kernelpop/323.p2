#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>

#include "Lexer.h"
#include "Parser.h"

using namespace std;
using namespace this_thread;
using namespace chrono;

string Test_File = "test_X.txt";
string _Language = "A3";

// Need to remove
vector<string> _Strings;
vector<Token> _Tokens;

int pause_time = 500;	// Milliseconds

vector<Token> runLexer(string file);
void runParser(vector<Token> tokenList);

int main() {
	int x = 0;
	while (true) {
		cout << "Please input a test number (1-8): ";
		cin >> x;
		
		if (x < 0) {
			break;
		}

		Test_File = "./tests/test_" + to_string(x) + ".txt";
		
		if (!cin.fail()) {

			ifstream f(Test_File.c_str());

			if (f.good()) {

				cout << "========  Start Test - " << Test_File << " ========" << endl;

				vector<Token> tokens = runLexer(Test_File);

				runParser(tokens);

				// _Strings.clear();

				// _Tokens.clear();

				cout << "========  End Test - " << Test_File << "  ========" << endl;

			} else {

				cout << "No such file found in current directory!" << endl;
			}
		} else {

			cout << "Bad input detected." << endl;

			cin.clear();

			cin.ignore(INT_MAX, '\n');
		}
	}
	return 0;
}

vector<Token> runLexer(string file) {
	Lexer lexer(_Language, Test_File);
	vector<Token> tokens = lexer.tokenize();
    
    cout << endl << "--- Token List ---" << endl;
    
	lexer.printTokens();

	return tokens;
}

void runParser(vector<Token> tokenList) {

//	cout << ">>> Parser Running" << endl;
//	sleep_until(system_clock::now() + milliseconds(pause_time));

	Parser parser;
//	cout << ">>> Created Parser object 'parser'" << endl;
//	sleep_until(system_clock::now() + milliseconds(pause_time));

//	cout << ">>> Sending tokens to 'parser'" << endl;
//	sleep_until(system_clock::now() + milliseconds(pause_time));
    parser.addTokensToParser(tokenList);
//	sleep_until(system_clock::now() + milliseconds(pause_time));
	
	
	parser.makePST();
//	cout << ">>> Created PST" << endl;
//	sleep_until(system_clock::now() + milliseconds(pause_time));

//	cout << ">>> Printing PST" << endl;
//	sleep_until(system_clock::now() + milliseconds(pause_time));
    cout << endl << "--- PST ---" << endl;
    parser.printPST();
//	sleep_until(system_clock::now() + milliseconds(pause_time));

	cout << endl << "--- Symbol Table ---" << endl;
    parser.printSymTable();

	parser.makeAST();
//	cout << ">>> Created AST" << endl;
//	sleep_until(system_clock::now() + milliseconds(pause_time));

//	cout << ">>> Printing AST" << endl;
//	sleep_until(system_clock::now() + milliseconds(pause_time));
	cout << endl << "--- AST ---" << endl;
    parser.printAST();
//	sleep_until(system_clock::now() + milliseconds(pause_time));

//	cout << ">>> Parser Done" << endl;
}
