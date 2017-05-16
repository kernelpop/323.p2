#include <iostream>
#include <string>

#include "Symbol.h"
#include "Rule.h"

using namespace std;

Symbol::Symbol(){ }

Symbol::Symbol(string rName, bool rIsTerminal) {
  name = rName;
  isTerminal = rIsTerminal;
}

Symbol::Symbol(Symbol* oldSymbol) {
    name = oldSymbol->name;
    isTerminal = oldSymbol->isTerminal;
}

Symbol::~Symbol() {}

string Symbol::getName() {
  return name;
}

bool Symbol::isTerm() {
  return isTerminal;
}

string Symbol::toString() const {
  string s;
  s += name;
  s += " - ";
  if(isTerminal)
    s += "Terminal symbol";
  else
    s += "NonTerminal symbol";

  return s;
}

ostream& operator<<(ostream& os, const Symbol& sym) {
  os << sym.toString();
  return os;
}

/*bool Symbol::operator==(Symbol &rhs) const{
    return this->name == rhs.name;
} */
