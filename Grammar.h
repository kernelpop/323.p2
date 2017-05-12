#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <map>
#include <vector>
#include <string>

#include "Symbol.h"
#include "Terminal.h"
#include "NonTerminal.h"
#include "Rule.h"

class Grammar {
private:
    std::map<std::string, Symbol*> terminals;
    std::map<std::string, Symbol*> nonTerminals;
    std::map<std::string, int> parseMatrix;
    std::vector<Rule*> rules;

    void createTerminals();
    void createNonTerminals();
    void createRules();
    void createParseMatrix();

public:
    Grammar();
    ~Grammar();

    Symbol* getTerminal(std::string term);
    Symbol* getNonTerminal(std::string nonTerm);
    Rule getRuleAt(std::string row, std::string col);
    Symbol getRule(std::string rule);

};

#endif
