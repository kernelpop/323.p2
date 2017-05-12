#include <map>
#include <vector>
#include <string>

#include "Grammar.h"
#include "Symbol.h"
#include "Terminal.h"
#include "NonTerminal.h"
#include "Rule.h"

using namespace std;

Grammar::Grammar() {
    createTerminals();
    createNonTerminals();
    createRules();
    createParseMatrix();
}

Grammar::~Grammar() {}

void Grammar::createTerminals() {
    terminals["kwdprog"] = new Terminal("kwdprog", new Token("kwdprog"));
    terminals["kwdinput"] = new Terminal("kwdinput", new Token("kwdinput"));
    terminals["kwdprint"] = new Terminal("kwdprint", new Token("kwdprint"));
    terminals["kwdwhile"] = new Terminal("kwdwhile", new Token("kwdwhile"));
    terminals["kwdif"] = new Terminal("kwdif", new Token("kwdif"));
    terminals["kwdelseif"] = new Terminal("kwdelseif", new Token("kwdelseif"));
    terminals["kwdelse"] = new Terminal("kwdelse", new Token("kwdelse"));
    terminals["paren1"] = new Terminal("paren1", new Token("paren1"));
    terminals["paren2"] = new Terminal("paren2", new Token("paren2"));
    terminals["brace1"] = new Terminal("brace1", new Token("brace1"));
    terminals["brace2"] = new Terminal("brace2", new Token("brace2"));
    terminals["comma"] = new Terminal("comma", new Token("comma"));
    terminals["semi"] = new Terminal("semi", new Token("semi"));
    terminals["equal"] = new Terminal("equal", new Token("equal"));
    terminals["plus"] = new Terminal("plus", new Token("plus"));
    terminals["minus"] = new Terminal("minus", new Token("minus"));
    terminals["aster"] = new Terminal("aster", new Token("aster"));
    terminals["slash"] = new Terminal("slash", new Token("slash"));
    terminals["caret"] = new Terminal("caret", new Token("caret"));
    terminals["id"] = new Terminal("id", new Token("id"));
    terminals["int"] = new Terminal("int", new Token("int"));
    terminals["float"] = new Terminal("float", new Token("float"));
    terminals["string"] = new Terminal("string", new Token("string"));
    terminals["$"] = new Terminal ("$", new Token("$"));
    terminals["eps"] = new Terminal("eps");
}

void Grammar::createNonTerminals() {
    nonTerminals["Opmul"] = new NonTerminal("Opmul", 1);
    nonTerminals["Opadd"] = new NonTerminal("Opadd", 2);
    nonTerminals["Fatom"] = new NonTerminal("Fatom", 3);
    nonTerminals["Pexpr"] = new NonTerminal("Pexpr", 4);
    nonTerminals["F"] = new NonTerminal("F", 5);
    nonTerminals["T"] = new NonTerminal("T", 5);
    nonTerminals["S"] = new NonTerminal("S", 5);
    nonTerminals["E"] = new NonTerminal("E", 5);
    nonTerminals["R"] = new NonTerminal("R", 5);
    nonTerminals["Elist2"] = new NonTerminal("Elist2", 6);
    nonTerminals["Elist"] = new NonTerminal("Elist", 6);
    nonTerminals["Else2"] = new NonTerminal("Else2", 6);
    nonTerminals["Fstmt"] = new NonTerminal("Fstmt", 6);
    nonTerminals["Wstmt"] = new NonTerminal("Wstmt", 6);
    nonTerminals["Ostmt"] = new NonTerminal("Ostmt", 6);
    nonTerminals["Y"] = new NonTerminal("Y", 7);
    nonTerminals["Astmt"] = new NonTerminal("Astmt", 8);
    nonTerminals["Stmt"] = new NonTerminal("Stmt", 8);
    nonTerminals["Stmts"] = new NonTerminal("Stmts", 8);
    nonTerminals["Block"] = new NonTerminal("Block", 8);
    nonTerminals["Pgm"] = new NonTerminal("Pgm", 9);
}

void Grammar::createRules() {
    vector<Symbol*> temp;

    rules.push_back(NULL); // no rule at index 0

    // Rule 1
    temp.push_back(terminals["kwdprog"]);
    temp.push_back(nonTerminals["Block"]);
    rules.push_back(new Rule(nonTerminals["Pgm"], temp));
    temp.clear();

    // Rule 2
    temp.push_back(terminals["brace1"]);
    temp.push_back(nonTerminals["Stmts"]);
    temp.push_back(terminals["brace2"]);
    rules.push_back(new Rule(nonTerminals["Block"], temp));
    temp.clear();

    // Rule 3
    temp.push_back(nonTerminals["Stmt"]);
    temp.push_back(terminals["semi"]);
    temp.push_back(nonTerminals["Stmts"]);
    rules.push_back(new Rule(nonTerminals["Stmts"], temp));
    temp.clear();

    // Rule 4
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["Stmts"], temp));
    temp.clear();

    // Rule 5
    temp.push_back(nonTerminals["Astmt"]);
    rules.push_back(new Rule(nonTerminals["Stmt"], temp));
    temp.clear();

    // Rule 6
    temp.push_back(nonTerminals["Ostmt"]);
    rules.push_back(new Rule(nonTerminals["Stmt"], temp));
    temp.clear();

    // Rule 7
    temp.push_back(nonTerminals["Wstmt"]);
    rules.push_back(new Rule(nonTerminals["Stmt"], temp));
    temp.clear();

    // Rule 8
    temp.push_back(nonTerminals["Fstmt"]);
    rules.push_back(new Rule(nonTerminals["Stmt"], temp));
    temp.clear();

    // Rule 9
    temp.push_back(terminals["id"]);
    temp.push_back(terminals["equal"]);
    temp.push_back(nonTerminals["Y"]);
    rules.push_back(new Rule(nonTerminals["Astmt"], temp));
    temp.clear();

    // Rule 10
    temp.push_back(terminals["kwdinput"]);
    rules.push_back(new Rule(nonTerminals["Y"], temp));
    temp.clear();

    // Rule 11
    temp.push_back(nonTerminals["E"]);
    rules.push_back(new Rule(nonTerminals["Y"], temp));
    temp.clear();

    // Rule 12
    temp.push_back(terminals["kwdprint"]);
    temp.push_back(terminals["paren1"]);
    temp.push_back(nonTerminals["Elist"]);
    temp.push_back(terminals["paren2"]);
    rules.push_back(new Rule(nonTerminals["Ostmt"], temp));
    temp.clear();

    // Rule 13
    temp.push_back(terminals["kwdwhile"]);
    temp.push_back(nonTerminals["Pexpr"]);
    temp.push_back(nonTerminals["Block"]);
    rules.push_back(new Rule(nonTerminals["Wstmt"], temp));
    temp.clear();

    // Rule 14
    temp.push_back(terminals["kwdif"]);
    temp.push_back(nonTerminals["Pexpr"]);
    temp.push_back(nonTerminals["Block"]);
    temp.push_back(nonTerminals["Else2"]);
    rules.push_back(new Rule(nonTerminals["Fstmt"], temp));
    temp.clear();

    // Rule 15
    temp.push_back(terminals["kwdelseif"]);
    temp.push_back(nonTerminals["Pexpr"]);
    temp.push_back(nonTerminals["Block"]);
    temp.push_back(nonTerminals["Else2"]);
    rules.push_back(new Rule(nonTerminals["Else2"], temp));
    temp.clear();

    // Rule 16
    temp.push_back(terminals["kwdelse"]);
    temp.push_back(nonTerminals["Block"]);
    rules.push_back(new Rule(nonTerminals["Else2"], temp));
    temp.clear();

    // Rule 17
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["Else2"], temp));
    temp.clear();

    // Rule 18
    temp.push_back(nonTerminals["E"]);
    temp.push_back(nonTerminals["Elist2"]);
    rules.push_back(new Rule(nonTerminals["Elist"], temp));
    temp.clear();

    // Rule 19
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["Elist"], temp));
    temp.clear();

    // Rule 20
    temp.push_back(terminals["comma"]);
    temp.push_back(nonTerminals["Elist"]);
    rules.push_back(new Rule(nonTerminals["Elist2"], temp));
    temp.clear();

    // Rule 21
    temp.push_back(nonTerminals["Opadd"]);
    temp.push_back(nonTerminals["T"]);
    temp.push_back(nonTerminals["R"]);
    rules.push_back(new Rule(nonTerminals["R"], temp));
    temp.clear();

    // Rule 22
    temp.push_back(nonTerminals["T"]);
    temp.push_back(nonTerminals["R"]);
    rules.push_back(new Rule(nonTerminals["E"], temp));
    temp.clear();

    // Rule 23
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["R"], temp));
    temp.clear();

    // Rule 24
    temp.push_back(nonTerminals["Opmul"]);
    temp.push_back(nonTerminals["F"]);
    temp.push_back(nonTerminals["S"]);
    rules.push_back(new Rule(nonTerminals["S"], temp));
    temp.clear();

    // Rule 25
    temp.push_back(nonTerminals["F"]);
    temp.push_back(nonTerminals["S"]);
    rules.push_back(new Rule(nonTerminals["T"], temp));
    temp.clear();

    // Rule 26
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["S"], temp));
    temp.clear();

    // Rule 27
    temp.push_back(nonTerminals["Fatom"]);
    rules.push_back(new Rule(nonTerminals["F"], temp));
    temp.clear();

    // Rule 28
    temp.push_back(nonTerminals["Pexpr"]);
    rules.push_back(new Rule(nonTerminals["F"], temp));
    temp.clear();

    // Rule 29
    temp.push_back(terminals["paren1"]);
    temp.push_back(nonTerminals["E"]);
    temp.push_back(terminals["paren2"]);
    rules.push_back(new Rule(nonTerminals["Pexpr"], temp));
    temp.clear();

    // Rule 30
    temp.push_back(terminals["id"]);
    rules.push_back(new Rule(nonTerminals["Fatom"], temp));
    temp.clear();

    // Rule 31
    temp.push_back(terminals["int"]);
    rules.push_back(new Rule(nonTerminals["Fatom"], temp));
    temp.clear();

    // Rule 32
    temp.push_back(terminals["float"]);
    rules.push_back(new Rule(nonTerminals["Fatom"], temp));
    temp.clear();

    // Rule 33
    temp.push_back(terminals["string"]);
    rules.push_back(new Rule(nonTerminals["Fatom"], temp));
    temp.clear();

    // Rule 34
    temp.push_back(terminals["plus"]);
    rules.push_back(new Rule(nonTerminals["Opadd"], temp));
    temp.clear();

    // Rule 35
    temp.push_back(terminals["minus"]);
    rules.push_back(new Rule(nonTerminals["Opadd"], temp));
    temp.clear();

    // Rule 36
    temp.push_back(terminals["aster"]);
    rules.push_back(new Rule(nonTerminals["Opmul"], temp));
    temp.clear();

    // Rule 37
    temp.push_back(terminals["slash"]);
    rules.push_back(new Rule(nonTerminals["Opmul"], temp));
    temp.clear();

    // Rule 38
    temp.push_back(terminals["caret"]);
    rules.push_back(new Rule(nonTerminals["Opmul"], temp));
    temp.clear();

    // Rule 39
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["Elist2"], temp));
    temp.clear();
}

void Grammar::createParseMatrix() {
    parseMatrix["Pgm_kwdprog"] = 1;
    parseMatrix["Block_brace1"] = 2;
    parseMatrix["Stmts_kwdprint"] = 3;
    parseMatrix["Stmts_kwdwhile"] = 3;
    parseMatrix["Stmts_kwdif"] = 3;
    parseMatrix["Stmts_id"] = 3;
    parseMatrix["Stmts_brace2"] = 4;
    parseMatrix["Stmt_kwdprint"] = 6;
    parseMatrix["Stmt_kwdwhile"] = 7;
    parseMatrix["Stmt_id"] = 5;
    parseMatrix["Astmt_id"] = 9;
    parseMatrix["Y_kwdinput"] = 10;
    parseMatrix["Y_id"] = 11;
    parseMatrix["Y_int"] = 11;
    parseMatrix["Y_float"] = 11;
    parseMatrix["Y_string"] = 11;
    parseMatrix["Y_paren1"] = 11;
    parseMatrix["Ostmt_kwdprint"] = 12;
    parseMatrix["Wstmt_kwdwhile"] = 13;
    parseMatrix["Fstmt_kwdif"] = 14;
    parseMatrix["Else2_kwdelseif"] = 15;
    parseMatrix["Else2_kwdelse"] = 16;
    parseMatrix["Else2_semi"] = 17;
    parseMatrix["Elist_id"] = 18;
    parseMatrix["Elist_int"] = 18;
    parseMatrix["Elist_float"] = 18;
    parseMatrix["Elist_string"] = 18;
    parseMatrix["Elist_paren1"] = 18;
    parseMatrix["Elist_paren2"] = 19;
    parseMatrix["Elist2_comma"] = 20;
    parseMatrix["R_plus"] = 21;
    parseMatrix["R_minus"] = 21;
    parseMatrix["R_comma"] = 23;
    parseMatrix["R_semi"] = 23;
    parseMatrix["R_paren2"] = 23;
    parseMatrix["E_id"] = 22;
    parseMatrix["E_int"] = 22;
    parseMatrix["E_float"] = 22;
    parseMatrix["E_string"] = 22;
    parseMatrix["E_paren1"] = 22;
    parseMatrix["S_plus"] = 26;
    parseMatrix["S_minus"] = 26;
    parseMatrix["S_aster"] = 24;
    parseMatrix["S_slash"] = 24;
    parseMatrix["S_caret"] = 24;
    parseMatrix["S_comma"] = 26;
    parseMatrix["S_semi"] = 26;
    parseMatrix["S_paren2"] = 26;
    parseMatrix["T_id"] = 25;
    parseMatrix["T_int"] = 25;
    parseMatrix["T_float"] = 25;
    parseMatrix["T_string"] = 25;
    parseMatrix["T_paren1"] = 25;
    parseMatrix["F_id"] = 27;
    parseMatrix["F_int"] = 27;
    parseMatrix["F_float"] = 27;
    parseMatrix["F_string"] = 27;
    parseMatrix["F_paren1"] = 28;
    parseMatrix["Pexpr_paren1"] = 29;
    parseMatrix["Fatom_id"] = 30;
    parseMatrix["Fatom_int"] = 31;
    parseMatrix["Fatom_float"] = 32;
    parseMatrix["Fatom_string"] = 33;
    parseMatrix["Opadd_plus"] = 34;
    parseMatrix["Opadd_minus"] = 35;
    parseMatrix["Opmul_aster"] = 36;
    parseMatrix["Opmul_slash"] = 37;
    parseMatrix["Opmul_caret"] = 38;
    parseMatrix["Elist2_paren2"] = 39;
}

Symbol* Grammar::getTerminal(string term) {
    return terminals[term];
}

Symbol* Grammar::getNonTerminal(std::string nonTerm){
    return nonTerminals[nonTerm];
}

Rule Grammar::getRuleAt(string row, string col) {
    string row_col = row + "_" + col;
    if(parseMatrix.count(row_col) > 0) {    // Check if key exists
        int ruleNum = parseMatrix[row_col];
        return *rules[ruleNum];
    }
    else {
        return *(new Rule());
    } 
}

Symbol Grammar::getRule(string rule) {
    return *terminals[rule];
}
