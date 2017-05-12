#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>

#include "Token.h"

class Lexer {
private:
    static const std::string NOTKWD;
    static const std::string keyWord[13];

    std::string _language;
    std::vector<std::string> stringList;
    std::vector<Token> tokenList;

    bool isLetter(char chr, bool isFirstChar);
    bool isNumber(char chr, bool isFirstChar);
    std::string whichKwd(std::string word);
    std::string whichNumType(std::string num);
    Token tokenate(int ln, std::string id, int ix, std::string str);
    Token tokenate(int ln, std::string id, std::string str);
    Token tokenate(int ln, std::string id);
    std::vector<std::string> txtToStrings(std::string fileName);
    std::vector<Token> tokenize(std::vector<std::string>);

public:
    Lexer();
    Lexer(std::string language, std::string fileName);
    ~Lexer();

    std::vector<Token> tokenize();
    void printTokens();

};

#endif
