#include <string>

#include "Terminal.h"

using namespace std;

Terminal::Terminal(string rName, Token* rToken) : Symbol(rName, true)  {
    tkn = rToken;
}

Terminal::Terminal(string rName) : Symbol(rName, true) {}

Terminal::~Terminal() {
    delete tkn;
}

Token* Terminal::getToken() {
    return tkn;
}
