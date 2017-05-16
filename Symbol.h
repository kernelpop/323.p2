#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

// class Rule;

class Symbol {
private:
  std::string name;
  int ruleId;
  bool isTerminal;
  bool isNeeded;


public:
  Symbol();
  Symbol(std::string rName, bool rIsTerminal);
  Symbol(Symbol* oldSymbol);
  ~Symbol();

  std::string getName();
  bool isTerm();
  std::string toString() const;
  // Rule* getRule();
  // int getRuleIx();


  friend std::ostream& operator<<(std::ostream& os, const Symbol& sym);

};

#endif
