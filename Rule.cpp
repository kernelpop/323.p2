#include <vector>
#include <string>

#include "Rule.h"

using namespace std;

Rule::Rule(Symbol* rLhs, vector<Symbol*> rRhs) {
    lhs = rLhs;
    rhs = rRhs;
}

Rule::Rule(Symbol* rLhs, std::vector<Symbol*> rRhs,
        int _opChildIx, int _lChildIx, int _rChildIx) {
    lhs = rLhs;
    rhs = rRhs;

    opChildIx = _opChildIx;
    lChildIx = _lChildIx;
    rChildIx = _rChildIx;
}
    
Rule::Rule() {}

Rule::~Rule() {
    // delete lhs;
    // while(!rhs.empty()) {
    //  delete rhs.front();
    //  rhs.pop_front();
    // }
}

void Rule::setOpChildIx(int ix) {
    opChildIx = ix;
}

void Rule::setLChildIx(int ix) {
    lChildIx = ix;
}

void Rule::setRChildIx(int ix) {
    rChildIx = ix;
}

int Rule::getOpChildIx() {
    return opChildIx;
}

int Rule::getLChildIx() {
    return lChildIx;
}

int Rule::getRChildIx() {
    return rChildIx;
}

Symbol* Rule::getLhs() {
    return lhs;
}
  
vector<Symbol*> Rule::getRhs() {
    return rhs;
}

vector<Symbol*> Rule::getRhsReversed() {
    vector<Symbol*> reversed;
    for (int i = static_cast<int>(rhs.size()) - 1; i >= 0; --i) {
        reversed.push_back(rhs[i]);
    }

    return reversed;
}

bool Rule::isEmpty() {
    return rhs.empty();
}
    
string Rule::toString() {
    string s;
    s += lhs->getName();
    s += " = ";
    for (size_t i = 0; i < rhs.size(); i++) {
        s += rhs[i]->getName();
        s += " ";
    }

    return s;
}
