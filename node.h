#pragma once

#include <string>
#include <vector>
#include "symbol.h"

using namespace std;

class Node {
    
    symbol* content;
    
    Node* parent;
    
    int kidIx;
    
    
public:
    
    vector<Node*> children;
    
    Node() {}
    
    Node(symbol* rContent) {
        content = rContent;
    }
    
    Node(symbol* rContent, Node* rParent, int rIx) {
        content = rContent;
        parent = rParent;
        kidIx = rIx;
    }
    
    ~Node() {
        delete content;
        delete parent;
        
        for (size_t i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
    void setParent(Node * _parent) {
        parent = _parent;
    }
    
    Node * getParent() {
        if(parent) {
            return parent;
        } else {
            return NULL;
        }
    }
    
    Node* getChild(int ix) {
        if(ix >= children.size() || ix < 0){
            return NULL;
        } else {
            return children[ix];
        }
    }
    
    int getIx() {
        return kidIx;
    }
    
    void setSymbol(symbol * r_sym) {
        content = r_sym;
    }
    
    void insert(Node* newChild) {
        
        // Assign the kid his id
        // which is the current size
        newChild->kidIx = children.size();
        
        // set parent
        newChild->parent = this;
        
        // Add kid to kid list
        children.push_back(newChild);
    }
    
    void insert(Node* newChild, bool b) {
        
        // Add kid to kid list
        children.push_back(newChild);
    }
    
    // **This only works for mom with no children
    void insertChildren(vector<symbol*> children) {
        for(int i = 0; i < children.size(); i++) {
            insert(new Node(children[i], this, i), true);
        }
    }
    
    vector<Node*>* getChildren() {
        return &children;
    }
    
    Node find(string node) {
        if (children.empty()) {
            //return;
        }
        
        for (size_t i = 0; i < children.size(); ++i) {}
        
        return Node();
        
    }
    
    void remove(Node* child) {
        // children.erase(/*child position*/);
    }
    
    symbol * getSymbol() {
        return content;
    }
    
    static string toString(Node* ptr) {
        // Base step
        if(!ptr) {
            return "";
        }
        
        string s;
        
        s += ptr->content->toString();
        s += "\n";
        
        for(size_t i = 0; i < ptr->children.size(); ++i) {
            s += toString(ptr->children[i]);
            s += "\n";
        }
        
        return s;
    }
    
};
