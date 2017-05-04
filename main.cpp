#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "txt_to_strings.h"
#include "token.h"

using namespace std;

string Test_File = "test_X.txt";
vector<string> _Strings;
vector<token> _Tokens;
string _Language = "A3";

int main() {
	int x = 0;
	while (true) {
		cout << "Please input a test number (1-6): ";
		cin >> x;
		if (x < 0) {
			break;
		}
		Test_File = "test_" + to_string(x) + ".txt";
		if (!cin.fail()) {

			ifstream f(Test_File.c_str());

			if (f.good()) {

				cout << "========  Start Test - " << Test_File << " ========" << endl;

				_Strings = txt_to_strings(Test_File);

				_Tokens = tokenize(_Strings);

				token_printer(_Language, _Tokens);

				//runParser(_Tokens);

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
