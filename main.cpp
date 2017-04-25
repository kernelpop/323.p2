#include "tokenize.cpp"
#include "token.h"
#include "txt_to_strings.cpp"
#include "Parser.cpp"

using namespace std;

int main() {
    vector<Token> tokens = runTokenizer();
    runParser(tokens);
	return 0;
}

