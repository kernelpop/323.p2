#include <string>
#include "Symbol.cpp"

using namespace std;

class Node {
    Symbol* content;
    Node* parent;
    list<Node*> children;
public:
    Node(Symbol * rContent) {
        content = rContent;
    }
    ~Node();

    void insert(Node* newChild) {
        children.insert(newChild);
    }

	list<Node*> getChildren() {
		return children;
	}

    Node find(string node) {
        if (children.empty()) {
            if (content.name == node) {			// Please comment on the logic of this if statement, not sure I undersand it
                return content
            } else {
                return NULL;
            }
        }

        for (int i = 0; i < children.size(); ++i){
            children[i].find(node);
        }



    }

    void remove(Node* child) {
        children.remove(child);
    }

    string toString() {

    }
    
};