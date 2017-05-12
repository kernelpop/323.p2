#include <vector>
#include <string>

#include "NonTerminal.h"

using namespace std;

NonTerminal::NonTerminal(string rName, vector<Symbol> rRhs) : Symbol(rName, false) {
  rhs = rRhs;
}

NonTerminal::NonTerminal(string rName, int rRule) : Symbol(rName, false) {
  rule = rRule;
}

NonTerminal::NonTerminal(string rName) : Symbol(rName, false) {}

NonTerminal::~NonTerminal() {}
   
