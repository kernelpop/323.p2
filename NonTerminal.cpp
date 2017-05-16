#include <vector>
#include <string>

#include "NonTerminal.h"

using namespace std;

NonTerminal::NonTerminal(string rName, vector<Symbol> rRhs) : Symbol(rName, false) {
  rhs = rRhs;
}

NonTerminal::NonTerminal(string rName, Rule* rRule) : Symbol(rName, false) {
  rule = rRule;
}

NonTerminal::NonTerminal(string rName) : Symbol(rName, false) {}

NonTerminal::NonTerminal(Symbol nonT)  : Symbol(nonT.getName(), false) {}

NonTerminal::~NonTerminal() {}

void NonTerminal::setRule(Rule* ruleToAdd) {
    rule = ruleToAdd;
}

Rule* NonTerminal::getRule() {
    return rule;
}
