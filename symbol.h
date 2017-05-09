#pragma once

#include <iostream>
#include <list>
#include <string>
#include "token.h"

using namespace std;

class symbol {

    string name;
    
    bool isTerminal;

public:

    symbol() { }

	bool isTerm() {
		return isTerminal;
	}

    symbol(string rName, bool rIsTerminal) {
        name = rName;
        isTerminal = rIsTerminal;
    }

    ~symbol() {}

    string getName() {
        return name;
    }

    string toString() {
      string s;
      s += name;
      s += " - ";
      if(isTerminal)
        s += "Terminal symbol";
      else
        s += "NonTerminal symbol";

      return s;
    }
    
    /*bool Symbol::operator==(Symbol &rhs) const{
        return this->name == rhs.name;
    } */


};


class Terminal : public symbol {
  token* tkn;

public:
  Terminal(string rName, token* rToken) : symbol(rName, true) {
    tkn = rToken;
  }

  Terminal(string rName) : symbol(rName, true) {

  }

  ~Terminal() {
    delete tkn;
  }

  token* getToken() {
    return tkn;
  }
   
};


class NonTerminal : public symbol {                         //------ERROR
   vector<symbol> rhs;
   // Rule* rule;
   int rule;

public:
   NonTerminal(string rName, vector<symbol> rRhs) : symbol(rName, false) {
       rhs = rRhs;
   }

   NonTerminal(string rName, int rRule) : symbol(rName, false) {
        rule = rRule;
   }

   NonTerminal(string rName) : symbol(rName, false) {

   }

   ~NonTerminal() {}
   
};

