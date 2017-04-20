class Node {
    Symbol value;
    list<Node*> children;
public:
    Node(Symbol rValue) {
        value = rValue;
    }
    ~Node();
    
};