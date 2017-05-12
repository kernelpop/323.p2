#ifndef SYM_H
#define SYM_H

#include <string>
#include <vector>

struct occurence {
    int lineNum;
    int tokenNum;
    bool isDef;
};

class Sym {
private:
    int ln;
    std::string id;
    int ix;
    std::string str;
    bool isString;
    double valueDouble;
    std::string valueString;
    std::vector<occurence> occs;

public:
    Sym();
    Sym(int _ln, std::string _id, int _ix, std::string _str, double _valdb, std::string _valstr);
    ~Sym();

    std::string getStr();
    int getLn();
    int getIx();
    double getValDbl();
    std::string getValStr();

    void addOcc(int _ln, int _ix);
    int getNumOccs();
    int getOccLineNum(int occ);
    int getOccTokenNum(int occ);
    bool isOccDef(int occ);
};

#endif
