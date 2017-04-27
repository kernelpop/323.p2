#include <string>
#include <vector>
#include <map>
#include "token.h"
#include "Grammar.cpp"
#include "SymTable.cpp"
#include "Node.cpp"
#include <stack>


using namespace std;

class Parser {
	Grammar gmr;
	Node* pst;
	Node* ast;
	SymTable symTable;
	vector<Token> tokenList;

	Parser(Grammar rGmr) {
		gmr = rGmr;
		//symTable = new SymTable();			------ERROR
	}

	Parser() {
		//gmr = new Grammar();					------ERROR
	}

	/**
	    Add a list of Token to be parsed

	    @param tokenList a vector list of the tokens to parse
	*/
	void addTokensToParse(vector<Token> rTokenList) {
		tokenList = rTokenList;
	}

	/**
	    Make a Parse Tree from the current token list.
	*/
	void makePST() {
		// Setup:
		stack<Symbol> workingStack;
		//list<Token> inputStream(tokenList);				--------ERROR

		//workingStack.push(Symbol("$"));		// Add the eof symbol		------ERROR
		//inputStream.push_back(Token("$"));	// Add the eof token		------ERROR

		//workingStack.push(Symbol("Pgm"));	// Add the start symbol			------ERROR
		// pst = new Node(workingStack.top());

		while(!workingStack.empty()) {
			// int i = 0;
			Symbol top = workingStack.top();
			//Token front = inputStream.front();							------ERROR

			//if(top.isTerminal()) {										------ERROR
			//	if(top.name != front.id) {
			//		// TODO: throw an error
			//		// Error: epected x, found y, line front.line
			//	}
			//}

			// M1:
			list<Symbol> rule;// = gmr.getRule(top.name, front.id);			------ERROR
			if(!rule.empty()) {
				// Remove the top symbol from stack
				workingStack.pop();
				
				// Add the rule backwards
				for (int i = rule.size() - 1; i >= 0; --i) {
					//workingStack.push(rule[i]);							------ERROR
				}

				// Reassign the top variable
				top = workingStack.top();
			} else {
				// The rule is empty => there is no prediction for this

				// TODO: throw an error
				// Error: unexpected token found, line front.line
			}

			// M2
			// else if(top.isTerminal {
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

	void makeAST() {

	}

	/**
	    Take the tree and create a printable represenation of it

	    @param tree a node pointer to the tree to serialize
	*/
	string serializeTree(Node* tree) {
		
		if (tree->getChildren.empty()) {	// If the tree has no children, return a null string
			return "";
		}

		if (tree->getChildren[5]) {

		}

	}

};
