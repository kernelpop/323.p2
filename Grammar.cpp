#include <list>
#include "Symbol.cpp"

class Rule {
    Symbol lhs;
    list<Symbol> rhs;

    Rule(Symbol rLhs, list<Symbol> rRhs){
        lhs = rLhs;
        rhs = rRhs;
    }
    ~Rule();

    list<Symbol> rhsReversed() {
        list<Symbol> reversed(rhs);
        reversed.reverse();
        return reversed;
    }
    
};

class Grammar {
    static map<string, Symbols> rules;








static char terminals [] = {
    'kwdprog',
    'kwdinput',
    'kwdprint',
    'kwdwhile',
    'kwdif',
    'kwdelseif',
    'kwdelse',
    'paren1',
    'paren2',
    'brace1',
    'brace2',
    'comma',
    'semi',
    'equal',
    'plus',
    'minus',
    'aster',
    'slash',
    'caret',
    'id',
    'int',
    'float',
    'string',
    '$'
}

static map<string, Symbols>; = {
    'Pgm'
    'Block'
    'Stmts'
    'Stmt'
    'Astmt'
    'Y'
    'Ostmt'
    'Wstmt'
    'Fstmt'
    'Else2'
    'Elist'
    'Elist2'
    'R'
    'E'
    'S'
    'T'
    'F'
    'Pexpr'
    'Fatom'
    'Opadd'
    'Opmul'
}

static array<Rule> rules = {
    'kwdprog',
    'kwdinput',
    'kwdprint',
    'kwdwhile',
    'kwdif',
    'kwdelseif',
    'kwdelse',
    'paren1',
    'paren2',
    'brace1',
    'brace2',
    'comma',
    'semi',
    'equal',
    'plus',
    'minus',
    'aster',
    'slash',
    'caret',
    'id',
    'int',
    'float',
    'string',
    '$'
}

    

public:
    Grammar() {
        rules['Pgm'] = NonTerminal('Pgm');
        rules['Block'] = NonTerminal('Block');
        rules['Stmts'] = NonTerminal('Stmts');
        rules['Stmt'] = NonTerminal('Stmt');
        rules['Astmt'] = NonTerminal('Astmt');
        rules['Y'] = NonTerminal('Y');
        rules['Ostmt'] = NonTerminal('Ostmt');
        rules['Wstmt'] = NonTerminal('Wstmt');
        rules['Fstmt'] = NonTerminal('Fstmt');
        rules['Else2'] = NonTerminal('Else2');
        rules['Elist'] = NonTerminal('Elist');
        rules['Elist2'] = NonTerminal('Elist2');
        rules['R'] = NonTerminal('R');
        rules['E'] = NonTerminal('E');
        rules['S'] = NonTerminal('S');
        rules['T'] = NonTerminal('T');
        rules['F'] = NonTerminal('F');
        rules['Pexpr'] = NonTerminal('Pexpr');
        rules['Fatom'] = NonTerminal('Fatom');
        rules['Opadd'] = NonTerminal('Opadd');
        rules['Opmul'] = NonTerminal('Opmul');
    }
    ~Grammar();

    Rule getRuleAt(string top, string next) {

    }
    
};