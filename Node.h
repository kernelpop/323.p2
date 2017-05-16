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
    int childCount;
    std::vector<Node*> children;
    
public:
    Node();
    Node(Symbol* rContent);
    Node(Symbol* rContent, Node* rParent, int rIx);
    Node(Node* oldNode);
    ~Node();
    
    // Getters and Setters
    void setParent(Node* _parent);
    void setSymbol(Symbol * r_sym);
    void setIx(int ix);
    int getIx();
    Symbol* getSymbol();
    Node* getParent();
    Node* getChild(int ix);
    std::vector<Node*>* getChildren();
    int getChildCount();
    Node* getOpChildToHoist();
    Node* getLChildToHoist();
    Node* getRChildToHoist();

    // Tree operations
    void insert(Node* newChild);
    void insert(Node* newChild, bool b);
    void insertChildren(std::vector<Symbol*> children);
    Node find(std::string node);
    void remove(Node* child);
    void removeChildAt(int chldIx);
    
    // Other
    void addAstChildren(Node* mom);
    Node*  copyGutsTo(Node* target);
    bool hoistSelf();
    std::string localInfoStr();
    std::string toString(Node* ptr);
};

#endif
