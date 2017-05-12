#include <vector>
#include <string>

#include "Rule.h"

using namespace std;

Rule::Rule(Symbol* rLhs, vector<Symbol*> rRhs) {
    lhs = rLhs;
    rhs = rRhs;
}
    
Rule::Rule() {}

Rule::~Rule() {
    // delete lhs;
    // while(!rhs.empty()) {
    //  delete rhs.front();
    //  rhs.pop_front();
    // }
}
    
vector<Symbol*> Rule::getRhs() {
    return rhs;
}

vector<Symbol*> Rule::rhsReversed() {
    vector<Symbol*> reversed;
    for (int i = rhs.size() - 1; i >= 0; --i) {
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
