#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "txt_to_strings.h"
#include "token.h"
#include "parser.h"
#include "symbol.h"

using namespace std;

string Test_File = "test_X.txt";
vector<string> _Strings;
vector<token> _Tokens;
string _Language = "A3";

void runParser(vector<token> tokenList);

int main() {
	int x = 0;
	while (true) {
		cout << "Please input a test number (1-6): ";
		cin >> x;
		if (x < 0) {
			break;
		}
		Test_File = "./tests/test_" + to_string(x) + ".txt";
		if (!cin.fail()) {

			ifstream f(Test_File.c_str());

			if (f.good()) {

				cout << "========  Start Test - " << Test_File << " ========" << endl;

				_Strings = txt_to_strings(Test_File);

				_Tokens = tokenize(_Strings);

				token_printer(_Language, _Tokens);

				runParser(_Tokens);

				_Strings.clear();

				_Tokens.clear();

				cout << "========  End Test  ========" << endl;

			}

			else {

				cout << "No such file found in current directory!" << endl;

			}

		}
		else {

			cout << "Bad input detected." << endl;

			cin.clear();

			cin.ignore(INT_MAX, '\n');

		}
	}
	return 0;
}

void runParser(vector<token> tokenList) {
	
	cout << endl << ">>> Parser Running" << endl;

	for (size_t i = 0; i < tokenList.size(); ++i) {
		cout << tokenList[i].id << endl;
	}

	Parser parser;

	cout << "Parser created" << endl;

	//	Send the generated tokens to the parse machine
	parser.addTokensToParse(tokenList);

	cout << "Tokens sent to parser" << endl;

	Grammar g = parser.getGmr();

	cout << "Created grammar" << endl;

	vector<string> temp;

	temp.push_back("kwdprog");
	temp.push_back("kwdinput");
	temp.push_back("kwdprint");
	temp.push_back("kwdwhile");
	temp.push_back("kwdif");
	temp.push_back("kwdelseif");
	temp.push_back("kwdelse");
	temp.push_back("paren1");
	temp.push_back("paren2");
	temp.push_back("brace1");
	temp.push_back("brace2");
	temp.push_back("comma");
	temp.push_back("semi");
	temp.push_back("equal");
	temp.push_back("plus");
	temp.push_back("minus");
	temp.push_back("aster");
	temp.push_back("slash");
	temp.push_back("caret");
	temp.push_back("id");
	temp.push_back("int");
	temp.push_back("float");
	temp.push_back("string");
	temp.push_back("$");

	vector<string> temp2;

	temp2.push_back("Opmul");
	temp2.push_back("Opadd");
	temp2.push_back("Fatom");
	temp2.push_back("Pexpr");
	temp2.push_back("F");
	temp2.push_back("T");
	temp2.push_back("S");
	temp2.push_back("E");
	temp2.push_back("R");
	temp2.push_back("Elist2");
	temp2.push_back("Elist");
	temp2.push_back("Else2");
	temp2.push_back("Fstmt");
	temp2.push_back("Wstmt");
	temp2.push_back("Ostmt");
	temp2.push_back("Y");
	temp2.push_back("Astmt");
	temp2.push_back("Stmt");
	temp2.push_back("Stmts");
	temp2.push_back("Block");
	temp2.push_back("Pgm");

	cout << "Created temp list" << endl;

	/*for(size_t i = 0; i < temp.size(); i++) {
		symbol t = *g.terminals[temp[i]];
		cout << t.getName() << endl;
	}*/ 

	/*for(size_t i = 0; i < temp2.size(); i++) {
		symbol t = *g.nonTerminals[temp2[i]];
		cout << t.getName() << endl;
	}*/

	/*list<Rule*> rules = g.rules;
	for (auto it = rules.begin(); it != rules.end(); ++it) {
		cout << (*it)->printRule() << endl;
	}*/

	// Create PST
	parser.makePST();
	cout << "Created PST" << endl;

	parser.print_table();

	cout << ">>> Parser Done" << endl;
}
