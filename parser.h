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
const string PRT_LEVEL_FILL = "___";

class Parser {
	Grammar* gmr;
	Node* pst;
	Node* ast;
	SymTable symTable;
	vector<token> tokenList;
	Node* mom;

public:

	Parser(Grammar* rGmr) {
		gmr = rGmr;
	}

	Parser() {
		gmr = new Grammar();
	}
    
    ~Parser() {
        // delete gmr;
        // delete pst;
        // delete ast;
        // delete mom;
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

		// Setup
		vector<symbol*> workingStack;

		// Add the eof symbol to stack
		workingStack.push_back(gmr->terminals["$"]);

		// Add the start symbol to stack
		workingStack.push_back(gmr->nonTerminals["Pgm"]);		
		
		// Add the eof token to input 
		tokenList.push_back(token("$"));

		// Add $ as root
		pst = new Node(workingStack[0], NULL, 0);

		// Set mom to Pgm
		mom = pst;

		cout << "Finished setup" << endl;

		int tokenIx = 1; // base 1
		while(!workingStack.empty()) {
			symbol* top = workingStack.back();
			token front = tokenList.front();

			if(top->isTerm()) {
				// if it's an epsilon rule pop it off
				if(top->getName() == "eps") {
					
                    // check to see if mom has sibling
                    while( !( ( mom->getParent() )->getChild( mom->getIx() + 1 ) ) ) {
                        
                        if( mom->getParent() ) {
                            mom = mom->getParent();
                        }
                    }
                    mom = ( mom->getParent() )->getChild( mom->getIx() + 1 );
                    
                    cout << "Popping of eps rule." << endl;
					workingStack.pop_back();
                    
				}

				// if top it terminal check if it matches front
				else if(*(static_cast<Terminal*>(top)->getToken()) == front) {
					cout << "Matched: " << front.id;
					cout << ". Popping off the top and the front.\n";
					cout << "\tln: " << front.ln << " ix: " << front.ix << endl;

					// Add token to symtable if it is identifier
					if (front.id=="id") {
						Sym * temp = new Sym(front.ln,front.id,front.ix,front.str,0,"null");
						symTable.add_symbol(*temp);
					}

                    bool isAtTop = false;
					// Set mom to next kid
                    if(mom->getParent()) {
                        while( !( ( mom->getParent() )->getChild( mom->getIx() + 1 ) ) ) {
                            
                            if( mom->getParent() ) {
                                mom = mom->getParent();
                                
                                // if we're at the top of the tree
                                if(mom == pst) {
                                    isAtTop = true;
                                    break;
                                }
                            }
                        }
                        if(!isAtTop) {
                            mom = ( mom->getParent() )->getChild( mom->getIx() + 1 );
                        }
                    }
                    
					
					// Pop the top
					workingStack.pop_back();

					// Pop the front
					tokenList.erase(tokenList.begin());
					tokenIx++;
				}

				// if top doesn't match with front throw error
				else {
					cout << "Error occured when parsing token " << tokenIx << endl;
					cout << "Predicted: " << (static_cast<Terminal*>(top)->getToken())->id;
					cout << " but instead found: " << front.id << endl;

					break;
				}
			} 
			else {
				// M1: Top is a NonTerminal
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
					for (size_t i = 0; i < rhsRev.size(); ++i) {
						workingStack.push_back(rhsRev[i]);
						// Node * temp = new Node(rule.getRhs()[i]);
						// temp->setParent(pst);
						// pst->insert(temp);
					}

					// Add rule rhs to mom
					mom->insertChildren(rule.getRhs());
					
					// Set mom to first child
					mom = mom->getChild(0);

				} else {
					cout << "The rule is empty => there is no prediction for this";
					cout << endl;

					// print stack
					cout << "Current stack" << endl;
					for(int i = workingStack.size() - 1; i >= 0; i--) {
						//cout << *workingStack[i] << endl;
					}

					// print input stream
					cout << endl <<  "Current token stream" << endl;
					for (size_t  i = 0; i < tokenList.size(); ++i) {
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
	// Node * makeAST(Node * pst) {
	// 	Node * AST;
	// 	//	NEEDS IMPLEMENTATION
	// 	return AST;
	// }

	//This is the print function of a PST tree.
	//Implemented as a recursive pre-order function. 
	//NOTE: This is finished
	void printPST(Node * current,int level = 0)
	{
		if (current == nullptr)
		{
			cout << "null" << endl;
			return;
		}
		/*if (current->getParent() == nullptr) // ---------Checks for root - Found no use for this but kept just in case------------
		{

		}*/
		
		// Print out the children of current node
		for (size_t i = 0; i < current->children.size();++i)
		{
			// For loop which makes the tree level more obvious
			for (int i = 0; i < level; ++i)
			{
				// Uses filler to show levels(actual variable is found near the top)
				cout << PRT_LEVEL_FILL;
			}

			// Outputs the current node followed by the child node
			cout << "|-" << current->getSymbol()->getName() << "  >>>  " << current->children[i]->getSymbol()->getName() << endl;
		}
		//Enter each child of the current node using this function
		for (size_t i = 0; i < current->children.size(); ++i)
		{
			// Call function recursively using the child as parameter
			// In addition the level will be incremented
			printPST(current->children[i],++level);
		}


	}

	// The AST printing function implemented in-order
	void printAST(Node * current) {
		if (current == nullptr)
		{
			cout << "null" << endl;
			return;
		}
		printAST(current->getChildren()->at(0));
		cout << current->getSymbol()->getName() << endl;
		printAST(current->getChildren()->at(1));
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
