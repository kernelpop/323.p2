#include <string>

using namespace std;

struct Token {
	int ln;			// line number
	string id;		// id based on grammar
	int ix;			// optional; index number
	string str;		// optional; actual string
};

//  ========  Function Prototypes  ========
vector<Token> tokenize(vector<string> lines);
bool isLetter(char c, bool firstChar);
bool isNumber(char c, bool firstChar);
string whichKwd(string s);
string whichNumType(string s);
Token tokenate(int ln, string id, int ix, string str);
Token tokenate(int ln, string id, string str);
Token tokenate(int ln, string id);
static const string NOTKWD("NOTKWD");