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
		
		// Add the eof token to imp
		tokenList.push_back(token("$"));

		// cout << tokenList.back().id << FILE_PARSER << endl;		// Test if token created succesfully
		

		pst = new Node(workingStack.top());
		// pst->insert(new Node(gmr->terminals["$"]));
		cout << pst->toString(pst) << FILE_PARSER << endl;

		// cout << pst->toString() << FILE_PARSER << endl;
/*
			while(!workingStack.empty()) {
				// int i = 0;
				//Symbol top = workingStack.top();								------ERROR
				//Token front = inputStream.front();							------ERROR

		//	// M1:
		//	list<symbol> rule;		// = gmr.getRule(top.name, front.id);
		//	if(!rule.empty()) {
		//		// Remove the top symbol from stack
		//		workingStack.pop();
		//			
		//		// Add the rule backwards
		//		for (int i = rule.size() - 1; i >= 0; --i) {
		//			//workingStack.push(rule[i]);							------ERROR
		//		}

		//		// Reassign the top variable
		//			
		//		//top = workingStack.top();									------ERROR
		//	} 
		//	/*else {
		//		 The rule is empty => there is no prediction for this

		//		 TODO: throw an error
		//		 Error: unexpected token found, line front.line
		//	}*/

		//	// M2
		//	else {
		//		if (top.isTerm()) {
		//			// 	Error();
		//			// }

		//			// // M3
		//			// else if(gmr.getRule(top, front).isEmpty()){
		//			// 	Error();
		//			// }

		//			// // M4
		//			// else if(!gmr.getRule(top, front).isEmpty()) {
		//			// 	workingStack.pop();
		//			// 	workingStack.push(gmr.getRule(top, front).reverse());

		//			// }
		//			// else {
		//			// 	printStatus();
		//			// }
		//		}
		//	}
		//}
		
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
