#ifndef NONTERMINAL_H
#define NONTERMINAL_H

#include <vector>
#include <string>

#include "Symbol.h"

class NonTerminal : public Symbol {
private:
  std::vector<Symbol> rhs;
  int rule;

public:
  NonTerminal(std::string rName, std::vector<Symbol> rRhs);
  NonTerminal(std::string rName, int rRule);
  NonTerminal(std::string rName);
  ~NonTerminal();
};

#endif
