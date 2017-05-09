#pragma once

#include <string>
#include <vector>
#include <map>
#include "token.h"
#include "grammar.h"
#include "symtable.h"
#include "node.h"
#include <stack>


using namespace std;

const string FILE_PARSER = " - parser.h";

class Parser {
	Grammar* gmr;
	Node* pst;
	Node* ast;
	SymTable symTable;
	vector<token> tokenList;

public:

	Parser(Grammar* rGmr) {
		gmr = rGmr;
	}

	Parser() {
		gmr = new Grammar();
	}

	void print_table() {
		symTable.print_table();
	}
	
	void addTokensToParser(vector<token> _TokenList) {
		tokenList = _TokenList;
		cout << ">>>>>> Parser received " << tokenList.size() << " token(s)" << endl;
	}

	Node * makePST() {
		
		//	Setup
		stack<symbol*> workingStack;

		// Add the eof symbol to stack
		workingStack.push(gmr->terminals["$"]);

		// Add the start symbol to stack
		workingStack.push(gmr->nonTerminals["Pgm"]);		
		
		// Add the eof token to input 
		tokenList.push_back(token("$"));

		while(!workingStack.empty()) {
			int i = 0;
			symbol* top = workingStack.top();
			token front = tokenList.front();

			// M1:
			Rule rule = gmr->getRuleAt(top->getName(), front.id);
			if(!rule.isEmpty()) {

				cout << rule.printRule() << endl;

				// Remove the top symbol from stack
				// workingStack.pop();
					
				// Add the rule backwards
				// vector<symbol*> rhsRev = rule.rhsReversed();
				// for (int i = 0; i < rhsRev.size(); ++i) {
				// 	workingStack.push(rhsRev[i]);
				// }

				// Reassign the top variable
					
				//top = workingStack.top();									------ERROR
			} 
			/*else {
				 The rule is empty => there is no prediction for this

				 TODO: throw an error
				 Error: unexpected token found, line front.line
			}*/

			// M2
			else {
				if (top->isTerm()) {
					// 	Error();
					// }

					// // M3
					// else if(gmr.getRule(top, front).isEmpty()){
					// 	Error();
					// }

					// // M4
					// else if(!gmr.getRule(top, front).isEmpty()) {
					// 	workingStack.pop();
					// 	workingStack.push(gmr.getRule(top, front).reverse());

					// }
					// else {
					// 	printStatus();
					// }
				}
			}
		}
		
		return pst;

	}



	//Take the tree and create a printable represenation of it
	//@param tree a node pointer to the tree to serialize
	Node * makeAST(Node * pst) {
		Node * AST;
		//	NEEDS IMPLEMENTATION
		return AST;
	}

	//This is the print function of a PST tree.
	//Implemented as a recursive pre-order function. 
	//NOTE: this is unfinished
	void printPST(Node * current)
	{
		if (current == nullptr)
		{
			cout << "null" << endl;
			return;
		}
		/*else //may not be used
		{
			cout << current->getName() + " >>> ";

		}*/
		//for (int i = 0; i < current->getChildren().size(); ++i)
		for(auto it = current->getChildren().begin(); it != current->getChildren().begin(); ++it)
		{
			cout << current->getSymbol()->getName() << " >>> ";
			//printPST(current->it);
		}
		cout << endl;

	}

	void printAST(Node * current) {

	}
	
	Grammar getGmr() {
		return *gmr;
	}

};

// Stuff for making a tree
// cout << tokenList.back().id << FILE_PARSER << endl;		// Test if token created succesfully
		
		// Start building the PST
		// pst = new Node(workingStack.top());

		// For test purposes
		// pst->insert(new Node(gmr->terminals["$"]));
		// pst->insert(new Node(gmr->terminals["id"]));
		// pst->insert(new Node(gmr->terminals["int"]));
		// pst->insert(new Node(gmr->nonTerminals["Astmt"]));
		// pst->insert(new Node(gmr->nonTerminals["Block"]));
		// pst->insert(new Node(gmr->nonTerminals["Pexpr"]));
		// cout << Node::toString(pst) << FILE_PARSER << endl;

		// cout << pst->toString() << FILE_PARSER << endl;
