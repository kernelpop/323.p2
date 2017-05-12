#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

#include "Symbol.h"

class Node {
private:
    Symbol* content;
    Node* parent;
    int kidIx;
    std::vector<Node*> children;
    
public:
    Node();
    Node(Symbol* rContent);
    Node(Symbol* rContent, Node* rParent, int rIx);
    ~Node();
    
    void setParent(Node* _parent);
    void setSymbol(Symbol * r_sym);
    int getIx();
    Symbol* getSymbol();
    Node* getParent();
    Node* getChild(int ix);
    std::vector<Node*>* getChildren();

    void insert(Node* newChild);
    void insert(Node* newChild, bool b);
    void insertChildren(std::vector<Symbol*> children);
    Node find(std::string node);
    void remove(Node* child);
    
    std::string toString(Node* ptr);
};

#endif
