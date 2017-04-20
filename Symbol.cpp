

class Symbol {
    string name;
    bool isTerminal;
public:
    Symbol(string rName, bool rIsTerminal) {
        name = rName;
        isTerminal = rIsTerminal;
    }
    ~Symbol();
    
};

class Terminal : public Symbol {
    Token* token;
public:
    Terminal(string rName, Token* rToken) : Symbol(rName, true) {
        token = rToken;
    }
    ~Terminal();
    
};

class NonTerminal : public Symbol {
    Symbol* rhs;
public:
    NonTerminal(string rName, Symbol* rRhs) : Symbol(rName, false) {
        rhs = rRhs;
    }
    ~NonTerminal();
    
};

