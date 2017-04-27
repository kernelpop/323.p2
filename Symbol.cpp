#include <list>
#include <string>
#include "token.h"

using namespace std;

class Symbol {

    string name;
    
	bool isTerminal;

public:

	Symbol() {

	}

    Symbol(string rName, bool rIsTerminal) {
        name = rName;
        isTerminal = rIsTerminal;
    }
    ~Symbol();
    
    bool Symbol::operator==(Symbol &rhs) const{
        return this->name == rhs.name;
    } 
};


class Terminal : public Symbol {
    Token* token;
public:
    Terminal(string rName, list<Token> rToken) : Symbol(rName, true) {
        //token = rToken;													------ERROR
    }
    Terminal(string rName) : Symbol(rName, true) {
    }
    ~Terminal();
    
};


class NonTerminal : public Symbol {
    list<Symbol> rhs;
public:
    NonTerminal(string rName, list<Symbol> rRhs) : Symbol(rName, false) {
        rhs = rRhs;
    }
    ~NonTerminal();
    
};

