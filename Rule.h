#ifndef RULE_H
#define RULE_H

#include <vector>
#include <string>

#include "Symbol.h"

class Rule {
private:
    Symbol* lhs;
    std::vector<Symbol*> rhs;
    
    int opChildIx;
    int lChildIx;
    int rChildIx;

public:
    Rule(Symbol* rLhs, std::vector<Symbol*> rRhs);
    Rule(Symbol* rLhs, std::vector<Symbol*> rRhs,
        int _opChildIx, int _lChildIx, int _rChildIx);
    Rule();
    ~Rule();

    void setOpChildIx(int ix);
    void setLChildIx(int ix);
    void setRChildIx(int ix);
    int getOpChildIx();
    int getLChildIx();
    int getRChildIx();
    Symbol* getLhs();
    std::vector<Symbol*> getRhs();
    std::vector<Symbol*> getRhsReversed();


    bool isEmpty();
    std::string toString();
};

#endif
