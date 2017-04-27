#include <string>
#include <list>

using namespace std;

struct occurence {
    int lineNum;
    int tokenNum;
    bool isDef;
};

class Sym {
    int ix;
    string printName;
    bool isString;
    double valueDouble;
    string valueString;
    list<occurence> occurences;
public:
    Sym();
    ~Sym();
    
};

class SymTable {
    list<Sym> table;
public:
    SymTable();
    ~SymTable();
    
};