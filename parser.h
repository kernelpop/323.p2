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
		stack<symbol> workingStack;
		
		// Add the eof symbol
		workingStack.push(symbol("$",0));		

		// Add the eof token
		token eof;
		eof.id = "$";
		tokenList.push_back(eof);
		
		// Add the start symbol
		workingStack.push(symbol("Pgm",0));	
		
		// Start the tree
		Node * pst = new Node(&workingStack.top());
		
		// Add kwdprog
		symbol * t = new symbol("kwdprog",1);
		Node * temp = new Node(t);
		pst->insert(temp);
		
		//while(!workingStack.empty()) {
		//	
		//	int i = 0;
		//	
		//	symbol top = workingStack.top();
		//	
		//	token front = tokenList.front();

		//	if(top.isTerm()) {
		//		if(top.getName() != front.id) {
		//			
		//			// Throw and error: epected x, found y, line front.line
		//			cout << ">>>>>> Error: stack top is terminal" << endl;
		//			exit(1);

		//		}
		//	}

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
