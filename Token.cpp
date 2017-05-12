#include <string>

#include "Token.h"

using namespace std;

Token::Token() {
    _ln = -1;
    _id = "";
    _ix = -1;
    _str = "";
}

Token::Token(string rId) {
    _id = rId;
}

Token::Token(int ln, string id, int ix, string str) {
    _ln = ln;
    _id = id;
    _ix = ix;
    _str = str;
}

void Token::setLn(int ln) {
    _ln = ln;
}

void Token::setId(std::string id) {
    _id = id;
}

void Token::setIx(int ix) {
    _ix = ix;
}

void Token::setStr(std::string str) {
    _str = str;
}

int Token::getLn() {
    return _ln;
}

std::string Token::getId() {
    return _id;
}

int Token::getIx() {
    return _ix;
}

std::string Token::getStr() {
    return _str;
}

bool operator==(const Token& lhs, const Token& rhs) {
    return lhs._id == rhs._id;
}
