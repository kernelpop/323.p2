#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>

#include "Lexer.h"
#include "Token.h"


using namespace std;

const string Lexer::NOTKWD = "NOTKWD";
const string Lexer::keyWord[13] = { 
    "prog", "main", "fcn", "class",
    "float", "int", "string", "if",
    "elseif", "else", "while", "input",
    "print"
};

Lexer::Lexer() {

}

Lexer::Lexer(string language, string fileName) {
    _language = language;
    stringList = txtToStrings(fileName);
}

Lexer::~Lexer() {
    tokenList.clear();
    stringList.clear();
}

bool Lexer::isLetter(char chr, bool isFirstChar) {
    string str = string(1, chr);
    if (isFirstChar)
        return regex_match(str, regex("[a-zA-Z_]"));
    else
        return regex_match(str, regex("[a-zA-Z_0-9]"));
}

bool Lexer::isNumber(char chr, bool isFirstChar) {
    string str = string(1, chr);
    if (isFirstChar)
        return regex_match(str, regex("[-0-9]"));
    else
        return regex_match(str, regex("[\\.0-9]"));
}

 string Lexer::whichKwd(string word) {
    // TODO: Check whether string is a keyword
    //       otherwise return NOTKWD
    string key = "kwd";
    for (int i = 0; i < 13; ++i) {
        if (word == keyWord[i]) {
            key += keyWord[i];
            return key;
        }
    }

    return NOTKWD;
}

string Lexer::whichNumType(string num) {
    // TODO: Check whether string is a float
    //       or an int
    if (regex_match(num, regex("-?[0-9]*\\.[0-9]+"))) {
        return "float";
    }
    else if (regex_match(num, regex("-?[0-9]+"))) {
        return "int";
    }
    return "wrong";
}

Token Lexer::tokenate(int ln, string id, int ix, string str) {

    Token tkn = *new Token();
    tkn.setLn(ln);
    tkn.setId(id);
    tkn.setIx(ix);
    tkn.setStr(str);

    return tkn;
}

Token Lexer::tokenate(int ln, string id, string str) {

    Token tkn = *new Token();
    tkn.setLn(ln);
    tkn.setId(id);
    tkn.setStr(str);

    return tkn;
}

Token Lexer::tokenate(int ln, string id) {

    Token tkn = *new Token();
    tkn.setLn(ln);
    tkn.setId(id);

    return tkn;
}

vector<Token> Lexer::tokenize(vector<string> lines) {

    // Variable for token creation
    int currLine = 0;
    int currTokenIndex = 0;
    string currID;
    string currString;

    if (!lines.empty()) {               // Make sure lines is not empty
        for (size_t i = 0; i < lines.size(); i++) {            // Going through each line

            currLine++;     // Increment line number
            currTokenIndex = 0; // Reset token index

            for (size_t _char = 0; _char < lines[i].length(); _char++) {     // Going through each character in a line

                if (lines[i][_char] == '/') {

                    // Check for comments
                    if (lines[i][_char + 1] == '/') {
                        break;  // A comment has been found, stop processing this line and move on to the next
                    }
                    // 48 slash = '/'
                    else {
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "slash"));
                    }
                }
                else if (lines[i][_char] == '"') {  // The beginning of a string has been found
                    string s;
                    ++_char;
                    while (lines[i][_char] != '"') {    //  Until the quote is closed keep apending chars to the string
                        s.append(string(1, lines[i][_char]));
                        ++_char;
                    }
                    currTokenIndex++;
                    // create token for string
                    tokenList.push_back(tokenate(currLine, "string", s));
                }
                // If the first character is a letter extract
                // the whole word (from current character until
                // you reach a non-word character)
                else if (isLetter(lines[i][_char], true)) {
                    string s = string(1, lines[i][_char]);
                    _char++;
                    while (isLetter(lines[i][_char], false)) {
                        s.append(string(1, lines[i][_char]));
                        _char++;
                    }
                    _char--;
                    if (whichKwd(s) == NOTKWD) {         // If not a kwd then it's ident
                        currTokenIndex++;
                        // create token for ident
                        tokenList.push_back(tokenate(currLine, "id", currTokenIndex, s));
                    }
                    else {
                        currTokenIndex++;
                        // create token for kwd
                        tokenList.push_back(tokenate(currLine, whichKwd(s)));
                    }
                }
                else if (isNumber(lines[i][_char], true)) {
                    string intStr = string(1, lines[i][_char]);
                    _char++;

                    // ERROR Check: can't have -.1 need -0,1
                    while (isNumber(lines[i][_char], false)) {
                        intStr.append(string(1, lines[i][_char]));
                        _char++;
                    }
                    _char--;
                    if (whichNumType(intStr) == "int") {         // If not a float it's int
                        currTokenIndex++;
                        // create token for int
                        tokenList.push_back(tokenate(currLine, "int", intStr));
                    }
                    else if (whichNumType(intStr) == "float") {
                        currTokenIndex++;
                        // create token for float
                        tokenList.push_back(tokenate(currLine, "float", intStr));
                    }
                }
                else {
                    switch (lines[i][_char]) {
                        // Paired delimeters
                        // 6 comma = ','
                    case ',':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "comma"));
                        break;
                        // 7 semi = ';'
                    case ';':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "semi"));
                        break;
                        // 31 angle1 = '<'
                    case '<':
                        if (lines[i][_char + 1] == '=') {
                            // 54 ople = "<="
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "ople"));
                        }
                        // 56 opshl = "<<"
                        else if (lines[i][_char + 1] == '<') {
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "opshl"));
                        }
                        else {
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "angle1"));
                        }
                        break;
                        // 32 angle2 = '>'
                    case '>':
                        if (lines[i][_char + 1] == '=') {
                            // 55 opge = ">="
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "opge"));
                        }
                        else if (lines[i][_char + 1] == '>') {
                            // 57 opshr = ">>"
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "opshr"));
                        }
                        else {
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "angle2"));
                        }
                        break;
                        // 33 brace1 = '{'
                    case '{':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "brace1"));
                        break;
                        // 34 brace2 = '}'
                    case '}':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "brace2"));
                        break;
                        // 35 bracket1 = '['
                    case '[':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "bracket1"));
                        break;
                        // 36 bracket2 = ']'
                    case ']':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "bracket2"));
                        break;
                        // 37 parens1 = '('
                    case '(':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "paren1"));
                        break;
                        // 38 parens2 = ')'
                    case ')':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "paren2"));
                        break;
                        // Other punctuation
                        // 41 aster = '*'
                    case '*':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "aster"));
                        break;
                        // 42 caret = '^'
                    case '^':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "caret"));
                        break;
                        // 43 colon = ':'
                    case ':':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "colon"));
                        break;
                        // 44 dot = '.'
                    case '.':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "angle1"));
                        break;
                        // 45 equal = '='
                    case '=':
                        if (lines[i][_char + 1] == '=') {
                            // 52 opeq = "=="
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "opeq"));
                        }
                        else {
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "equal"));
                        }
                        break;
                        // 46 minus = '-'
                        //May need to include with number check
                    case '-':
                        if (lines[i][_char + 1] == '>') {
                            // 51 oparrow = "->"
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "oparrow"));
                        }
                        else {
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "minus"));
                        }
                        break;
                        // 47 plus = '+'
                    case '+':
                        currTokenIndex++;
                        tokenList.push_back(tokenate(currLine, "plus"));
                        break;
                        // 53 opne = "!="
                    case '!':
                        if (lines[i][_char + 1] == '=') {
                            currTokenIndex++;
                            tokenList.push_back(tokenate(currLine, "opne"));
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    return tokenList;
}

vector<Token> Lexer::tokenize() {
    return tokenize(stringList);
}

void Lexer::printTokens() {
    cout << "(:lang " << _language << endl; //  Print the language

    for (size_t i = 0; i < tokenList.size(); i++) {    // For each token in our tokens vector

        for (int i = 0; i < 3; i++) { // Indent the new line
            cout << " ";
        }

        cout << "(:token " << tokenList[i].getLn() << " " << tokenList[i].getId();  //  Print line number

        if (tokenList[i].getId() == "id") { //  If the token has an index, print it
            cout << " :ix " << tokenList[i].getIx();
        }

        if (tokenList[i].getId() == "id" |
            tokenList[i].getId() == "string" |
            tokenList[i].getId() == "int" |
            tokenList[i].getId() == "float") {
            cout << " :str \"" << tokenList[i].getStr() << "\"";    //  If the token has a str, print it
        }

        cout << ")" << endl;    //  Finish printing that token
    }

    cout << ")" << endl;    //  Finish the print function
}

vector<string> Lexer::txtToStrings(string fileName) {
    vector<string> strings;     // This is what our function will return
    ifstream reader;
    reader.open(fileName);
    while (!reader.eof()) {
        string new_string;
        getline(reader, new_string);
        strings.push_back(new_string);
    }
    return strings;
}

// _Strings = txt_to_strings(Test_File);

//              _Tokens = tokenize(_Strings);

//              token_printer(_Language, _Tokens);