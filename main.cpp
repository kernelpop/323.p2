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


//	========  Function Prototypes  ========
vector<Token> runTokenizer();
void runParser(vector<Token>);
vector<Token> tokenize(vector<string> lines);
bool isLetter(char c, bool firstChar);
bool isNumber(char c, bool firstChar);
string whichKwd(string s);
string whichNumType(string s);
Token tokenate(int ln, string id, int ix, string str);
Token tokenate(int ln, string id, string str);
Token tokenate(int ln, string id);
static const string NOTKWD("NOTKWD");

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
}