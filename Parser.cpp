#include <string>
#include <vector>
#include <map>

#include "Parser.h"
#include "Token.h"
#include "Grammar.h"
#include "SymTable.h"
#include "Node.h"

using namespace std;

Parser::Parser() {
    gmr = new Grammar();
}

Parser::Parser(Grammar* rGmr) {
    gmr = rGmr;
}

Parser::~Parser() {
    // delete gmr;
    // delete pst;
    // delete ast;
    // delete mom;
}


void Parser::printAST(Node * current) {
    if (current == nullptr) {
        cout << "null" << endl;
        return;
    }

    printAST(current->getChildren()->at(0));
    cout << current->getSymbol()->getName() << endl;
    printAST(current->getChildren()->at(1));
}

void Parser::printPST(Node* current, Node* root = nullptr) {
    if (current == nullptr) {
        cout << "null" << endl;
        return;
    }
    else if(current->getChildren()->size() == 0) {//checks for root
        cout << "\t" <<current->getSymbol()->getName() + " >>> " << endl;
        //current = current->getParent();
        return;
    }

    //  Lollipop mom
    cout << current->getSymbol()->getName() << " >>> " << endl;
    for (size_t i = 0; i < current->getChildren()->size(); ++i) {
        
        current = current->getChildren()->at(i);
        //printPST(current->getChildren()->at(i),root);
        printPST(current, root);
        current = current->getParent();
    }
    cout << endl;

}

void Parser::addTokensToParser(vector<Token> _TokenList) {
    tokenList = _TokenList;
    cout << ">>>>>> Parser received " << tokenList.size() << " token(s)" << endl;
}

Node* Parser::makePST() {
    
    cout << "Starting to parse token list" << endl;

    // Setup
    vector<Symbol*> workingStack;

    // Add the eof symbol to stack
    workingStack.push_back(gmr->getTerminal("$"));

    // Add the start symbol to stack
    workingStack.push_back(gmr->getNonTerminal("Pgm"));       
    
    // Add the eof token to input 
    tokenList.push_back(Token("$"));

    // Add $ as root
    pst = new Node(workingStack[0], NULL, 0);

    // Set mom to Pgm
    mom = pst;

    cout << "Finished setup" << endl;

    int tokenIx = 1; // base 1
    while(!workingStack.empty()) {
        Symbol* top = workingStack.back();
        Token front = tokenList.front();

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
                cout << "Matched: " << front.getId();
                cout << ". Popping off the top and the front.\n";
                cout << "\tln: " << front.getLn() << " ix: " << front.getIx() << endl;

                // Add token to symtable if it is identifier
                if (front.getId() == "id") {
                    Sym* temp = new Sym(front.getLn(), front.getId(), front.getIx(), front.getStr(), 0, "null");
                    symTable.addSymbol(*temp);
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
                cout << "Predicted: " << (static_cast<Terminal*>(top)->getToken())->getId();
                cout << " but instead found: " << front.getId() << endl;

                break;
            }
        } 
        else {
            // M1: Top is a NonTerminal
            Rule rule = gmr->getRuleAt(top->getName(), front.getId());

            cout << "Checking for rule: ";
            cout << "(" << top->getName() << ", " << front.getId() << ")";
            cout << endl;

            if(!rule.isEmpty()) {

                cout << "This rule was found: ";
                cout << rule.toString() << endl;

                // Remove the top symbol from stack
                workingStack.pop_back();
                    
                // Add the rule in reverse
                vector<Symbol*> rhsRev = rule.rhsReversed();
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
                    cout << tokenList[i].getId() << endl;
                }

                break;
            } 
        }
    }
    
    return pst;

}

Node* Parser::makeAST() { return new Node(); }

void Parser::printPST() {
    printPST(pst);
}

void Parser::printAST() {}


void Parser::printSymTable() {
    symTable.printTable();
}
