#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

class Symbol {
private:
  std::string name;
  bool isTerminal;

public:
  Symbol();
  Symbol(std::string rName, bool rIsTerminal);
  ~Symbol();

  std::string getName();
  bool isTerm();
  std::string toString() const;

  friend std::ostream& operator<<(std::ostream& os, const Symbol& sym);

};

#endif
