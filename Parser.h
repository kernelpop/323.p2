#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

#include "Grammar.h"
#include "Token.h"
#include "Node.h"
#include "SymTable.h"
#include "Sym.h"

class Parser {
private:
	Grammar* gmr;
	Node* pst;
	Node* ast;
	SymTable symTable;
	std::vector<Token> tokenList;
	Node* mom;

	void printAST(Node * current);
    void printPST(Node* current, Node* root);

public:
	Parser();
	Parser(Grammar* rGmr);
    ~Parser();

    void addTokensToParser(std::vector<Token> _TokenList);
    Node* makePST();
    Node* makeAST();
    void printAST();
    void printPST();
	void printSymTable();
};

#endif
