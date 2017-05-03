#pragma once

#include <string>
#include <list>
// #include "Symbol.cpp"

using namespace std;

class Node {
    //Symbol* content;
    Node* parent;
    list<Node*> children;
public:
	Node() {

	}
    /*Node(Symbol * rContent) {			-----------ERROR
        content = rContent;
    }*/
    ~Node();

    void insert(Node* newChild) {
        //children.insert(newChild);  ------------ERROR
    }

	list<Node*> getChildren() {
		return children;
	}

    Node find(string node) {
        if (children.empty()) {
   //         if (content.name == node) {			----------Error
   //             return content
   //         } 
			//else {
   //             return NULL;
   //         }
        }

        for (size_t i = 0; i < children.size(); ++i){
            //children[i].find(node);						-----------Error
        }

        return Node();

    }

    void remove(Node* child) {
        children.remove(child);
    }

    string toString() {
        return "hello world";
    }
    
};