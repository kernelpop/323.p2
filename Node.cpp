class Node {
    Symbol* content;
    list<Node*> children;
public:
    Node(Symbol rContent) {
        content = rContent;
    }
    ~Node();

    void insert(Node* newChild) {
        children.insert(newChild);
    }

    Node find(string node) {
        if (children.empty()) {
            if (content.name == node) {
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