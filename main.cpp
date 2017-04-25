#include "tokenize.cpp"
#include "token.h"
#include "Parser.cpp"
#include "resources.h"

using namespace std;


//	========  Global Variables  ========
string _Language = "A3";
string Test_File = "test_X.txt";
vector<Token> _Tokens;
vector<string> _Strings;



int main() {
	
	_Tokens = runTokenizer(Test_File);
	// runParser(_Tokens);

	return 0;
}

vector<Token> runTokenizer(string file) {
	int x = 0;
	
	cout << "Please input a test number or a negative number to exit: ";
	cin >> x;
	
	if (x < 0) {
		exit(0);
    }
}

void runParser(vector<Token> tokenList) {
    Parser parser();
    parser.addTokensToParse(tokenList);
    parser.makePST();
    parser.makeAST();

}

