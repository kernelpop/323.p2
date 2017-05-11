#pragma once

#include <string>
#include <vector>
#include "symbol.h"

using namespace std;

class Node {
	
	symbol* content;
	
	Node* parent;
	vector<Node*> children;

public:
	
	Node() {}

	Node(symbol* rContent) {
		content = rContent;
	}
	
	void setSymbol(symbol * r_sym) {
		content = r_sym;
	}

	~Node() {}

	void insert(Node* newChild) {
		children.push_back(newChild);
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
