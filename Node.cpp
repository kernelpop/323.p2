#include <string>
#include <vector>

#include "Node.h"

using namespace std;

Node::Node() {}

Node::Node(Symbol* rContent) {
    content = rContent;
}

Node::Node(Symbol* rContent, Node* rParent, int rIx) {
    content = rContent;
    parent = rParent;
    kidIx = rIx;
}

Node::~Node() {
    delete content;
    delete parent;
    
    for (size_t i = 0; i < children.size(); i++) {
        delete children[i];
    }
}

void Node::setParent(Node* _parent) {
    parent = _parent;
}

void Node::setSymbol(Symbol * rSym) {
    content = rSym;
}

int Node::getIx() {
    return kidIx;
}

Symbol* Node::getSymbol() {
    return content;
}

Node* Node::getParent() {
    if(parent) {
        return parent;
    } else {
        return NULL;
    }
}

Node* Node::getChild(int ix) {
    if(ix >= children.size() || ix < 0) {
        return NULL;
    }
    else {
        return children[ix];
    }
}

vector<Node*>* Node::getChildren() {
    return &children;
}

void Node::insert(Node* newChild) {
        
    // Assign the kid his id
    // which is the current size
    newChild->kidIx = children.size();
    
    // set parent
    newChild->parent = this;
    
    // Add kid to kid list
    children.push_back(newChild);
}

void Node::insert(Node* newChild, bool b) {
        
    // Add kid to kid list
    children.push_back(newChild);
}

void Node::insertChildren(vector<Symbol*> children) {
    for(int i = 0; i < children.size(); i++) {
        insert(new Node(children[i], this, i), true);
    }
}

Node Node::find(string node) {
    if (children.empty()) {
        //return;
    }
    
    for (size_t i = 0; i < children.size(); ++i) {}
    
    return Node();
    
}

void Node::remove(Node* child) {
    // children.erase(/*child position*/);
}

string Node::toString(Node* ptr) {
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
