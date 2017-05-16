#include "Sym.h"

using namespace std;


Sym::Sym() {}

Sym::Sym(int _ln, string _id, int _ix, string _str, double _valdb, string _valstr) {
    ln = _ln;
    id = _id;
    ix = _ix;
    str = _str;
    valueDouble = _valdb;
    valueString = _valstr;
}

Sym::~Sym() {}

string Sym::getStr() {
    return str;
}

int Sym::getLn() {
    return ln;
}

int Sym::getIx() {
    return ix;
}

double Sym::getValDbl() {
    return valueDouble;
}

std::string Sym::getValStr() {
    return valueString;
}


void Sym::addOcc(int _ln, int _ix) {
    occurence a;
    a.lineNum = _ln;
    a.tokenNum = _ix;
    a.isDef = false;
    occs.push_back(a);
}

int Sym::getNumOccs() {
    return static_cast<int>(occs.size());
}

int Sym::getOccLineNum(int occ) {
    return occs[occ].lineNum;
}

int Sym::getOccTokenNum(int occ) {
    return occs[occ].tokenNum;
}

bool Sym::isOccDef(int occ) {
    return occs[occ].isDef;
}
