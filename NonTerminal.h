#ifndef NONTERMINAL_H
#define NONTERMINAL_H

#include <vector>
#include <string>

#include "Symbol.h"
#include "Rule.h"

class NonTerminal : public Symbol {
private:
    std::vector<Symbol> rhs;
    Rule* rule;

public:
  NonTerminal(std::string rName, std::vector<Symbol> rRhs);
  NonTerminal(std::string rName, Rule* rRule);
  NonTerminal(std::string rName);
    NonTerminal(Symbol nonT);
  ~NonTerminal();

  void setRule(Rule* ruleToAdd);
  Rule* getRule();
};

#endif
