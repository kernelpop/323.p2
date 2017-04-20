#include <string>
#include <vector>
#include <map>
#include "Token.cpp"
#include "Grammar.cpp"
#include "SymTable.cpp"

using namespace std;

class Parser {
	Grammar gmr;
	Node* pst;
	Node* ast;
	SymTable symTable;
	vector<Token> tokenList;

	Parser(Grammar rGmr) {
		gmr = rGmr;
		symTable = new SymTable();
	}

	Parser() {
		gmr = new Grammer();
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
		list<Token> inputStream(tokenList);

		workingStack.push(Symbol("$"));		// Add the eof symbol
		inputStream.push_back(Token("$"));	// Add the eof token

		workingStack.push(Symbol("Pgm"));	// Add the start symbol
		// pst = new Node(workingStack.top());

		while(!workingStack.empty()) {
			// int i = 0;
			Symbol top = workingStack.top();
			Token front = inputStream.front();

			if(top.isTerminal) {
				if(top.name != front.id) {
					// TODO: throw an error
					// Error: epected x, found y, line front.line
				}
			}

			// M1:
			list<Symbol> rule = gmr.getRule(top.name, front.id);
			if(!rule.empty()) {
				// Remove the top symbol from stack
				workingStack.pop();
				
				// Add the rule backwards
				for (int i = rule.size() - 1; i >= 0; --i) {
					workingStack.push(rule[i]);
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
		// TODO: Serialize the tree
	}

}
