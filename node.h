#pragma once

#include <string>
#include <list>
#include "symbol.h"

using namespace std;

class Node {
	
	symbol* content;
	
	Node* parent;
	
	list<Node*> children;

public:
	
	Node() {}
	
	Node(symbol * rContent) {
		content = rContent;
	}
	
	~Node() {}

	void insert(Node* newChild) {}

	list<Node*> getChildren() {
		return children;
	}

	Node find(string node) {
		if (children.empty()) {}

		for (size_t i = 0; i < children.size(); ++i) {}

		return Node();

	}

	void remove(Node* child) {
		children.remove(child);
	}

	string toString() {
		return "hello world";
	}

};
