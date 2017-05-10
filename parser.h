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
		
		cout << "Starting to parse token list" << endl;

		//	Setup
		vector<symbol*> workingStack;

		// Add the eof symbol to stack
		workingStack.push_back(gmr->terminals["$"]);

		// Add the start symbol to stack
		workingStack.push_back(gmr->nonTerminals["Pgm"]);		
		
		// Add the eof token to input 
		tokenList.push_back(token("$"));

		cout << "finished setup" << endl;

		while(!workingStack.empty()) {
			symbol* top = workingStack.back();
			token front = tokenList.front();

			if(top->isTerm()) {
				// if it's an epsilon rule pop it off
				if(top->getName() == "eps") {
					cout << "Popping of eps rule." << endl;
					workingStack.pop_back();
				}

				// if top it terminal check if it matches front
				else if(*(static_cast<Terminal*>(top)->getToken()) == front) {	// ****may have to change this
					cout << "Matched: " << front.id;
					cout << ". Popping off the top and the front.\n";
					cout << "\tln: " << front.ln << " ix: " << front.ix << endl;

					// Pop the top
					workingStack.pop_back();

					// Pop the front
					tokenList.erase(tokenList.begin());
				}
			} else {
				// M1:
				Rule rule = gmr->getRuleAt(top->getName(), front.id);

				cout << "Checking for rule: ";
				cout << "(" << top->getName() << ", " << front.id << ")";
				cout << endl;

				if(!rule.isEmpty()) {

					cout << "This rule was found: ";
					cout << rule.printRule() << endl;

					// Remove the top symbol from stack
					workingStack.pop_back();
						
					// Add the rule in reverse
					vector<symbol*> rhsRev = rule.rhsReversed();
					for (int i = 0; i < rhsRev.size(); ++i) {
						workingStack.push_back(rhsRev[i]);
					}
				} else {
					cout << "The rule is empty => there is no prediction for this";
					cout << endl;

					// print stack
					cout << "Current stack" << endl;
					for(int i = workingStack.size() - 1; i >= 0; i--) {
						cout << *workingStack[i] << endl;
					}

					// print input stream
					cout << endl <<  "Current token stream" << endl;
					for (int  i = 0; i < tokenList.size(); ++i) {
						cout << tokenList[i].id << endl;
					}

					break;
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
	//NOTE: this is untested
	void printPST(Node * current,Node * root = nullptr)
	{
		if (current == nullptr)
		{
			cout << "null" << endl;
			return;
		}
		else if(current == root)//checks for root
		{
			cout << current->getSymbol()->getName() + " >>> ";

		}
		for (int i = 0; i < current->getChildren()->size(); ++i)//--------------------------for(auto it = current->getChildren().begin(); it != current->getChildren().begin(); ++it)
		{
			cout << current->getSymbol()->getName() << " >>> ";
			printPST(current->getChildren()->at(i),root);
		}
		cout << endl;

	}

	void printAST(Node * current) {

	}
	
	Grammar getGmr() {
		return *gmr;
	}

};


// Stuff for parser

			/*else {
				 The rule is empty => there is no prediction for this

				 TODO: throw an error
				 Error: unexpected token found, line front.line
			}*/

			// M2
			// else {
			// 	if (top->isTerm()) {
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
				// }
			// }



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
