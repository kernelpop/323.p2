#ifndef TERMINAL_H
#define TERMINAL_H
#include <string>

#include "Symbol.h"
#include "Token.h"

class Terminal : public Symbol {
private:
  Token* tkn;

public:
  Terminal(std::string rName, Token* rToken);
  Terminal(std::string rName);
  ~Terminal();

  Token* getToken();
};

#endif
