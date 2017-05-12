#ifndef RULE_H
#define RULE_H

#include <vector>
#include <string>

#include "Symbol.h"

class Rule {
private:
    Symbol* lhs;
    std::vector<Symbol*> rhs;

public:
    Rule(Symbol* rLhs, std::vector<Symbol*> rRhs);
    Rule();
    ~Rule();
    
    std::vector<Symbol*> getRhs();
    std::vector<Symbol*> rhsReversed();
    bool isEmpty();
    std::string toString();
};

#endif
