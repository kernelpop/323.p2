#include "Tokenizer.cpp"
#include "token.h"
#include "Parser.cpp"
#include "resources.h"

using namespace std;

//	========  Global Variables  ========
string _Language = "A3";
string Test_File = "test_X.txt";
vector<Token> _Tokens;
vector<string> _Strings;


//	========  Function Prototypes  ========
vector<Token> runTokenizer();
void runParser(vector<Token>);

int main() {
	
	_Tokens = runTokenizer();
	//runParser(_Tokens);

	return 0;
}

vector<Token> runTokenizer() {
	int x = 0;

	cout << "Please input a test number or a negative number to exit: ";
	cin >> x;

	if (x < 0) {
		exit(0);
	}

	Test_File = "test_" + to_string(x) + ".txt";

	//  Checks for correct input
	if (!cin.fail())
	{
		//  Checks if a file is available
		ifstream f(Test_File.c_str());                       //If true run lexer
		if (f.good())
		{
			// ========  Start Test  ========
			cout << "========  Start Test - " << Test_File << " ========" << endl;


			_Strings = txt_to_strings(Test_File);

			_Tokens = tokenize(_Strings);

			printer(_Language, _Tokens);

			_Strings.clear();


			cout << "========  End Test  ========" << endl;
			// ========  End Test  ========
		}                                                    //  Else output error
		else cout << "No such file found in current directory!" << endl;
	}
	else //  If output is not correct, display message and clear input stream
	{
		cout << "Wrong input detected." << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}