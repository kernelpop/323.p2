// Daniel Bravo        893863209   bravod@csu.fullerton.edu
// David Feinzimer     891774168   dfeinzimer@csu.fullerton.edu
// Mircea Dumitrache   890713464   dmircea@csu.fullerton.edu

// This is where our rules and parse matrix are defined using predefined grammar.


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
    nonTerminals["Opmul"] = new NonTerminal("Opmul");
    nonTerminals["Opmul_2"] = new NonTerminal("Opmul");
    nonTerminals["Opmul_3"] = new NonTerminal("Opmul");
    nonTerminals["Opadd"] = new NonTerminal("Opadd");
    nonTerminals["Opadd_2"] = new NonTerminal("Opadd");
    nonTerminals["Fatom"] = new NonTerminal("Fatom");
    nonTerminals["Fatom_2"] = new NonTerminal("Fatom");
    nonTerminals["Fatom_3"] = new NonTerminal("Fatom");
    nonTerminals["Fatom_4"] = new NonTerminal("Fatom");
    nonTerminals["Pexpr"] = new NonTerminal("Pexpr");
    nonTerminals["F"] = new NonTerminal("F");
    nonTerminals["F_2"] = new NonTerminal("F");
    nonTerminals["T"] = new NonTerminal("T");
    nonTerminals["S"] = new NonTerminal("S");
    nonTerminals["S_2"] = new NonTerminal("S");
    nonTerminals["E"] = new NonTerminal("E");
    nonTerminals["R"] = new NonTerminal("R");
    nonTerminals["R_2"] = new NonTerminal("R");
    nonTerminals["Elist2"] = new NonTerminal("Elist2");
    nonTerminals["Elist2_2"] = new NonTerminal("Elist2");
    nonTerminals["Elist"] = new NonTerminal("Elist");
    nonTerminals["Elist_2"] = new NonTerminal("Elist");
    nonTerminals["Else2"] = new NonTerminal("Else2");
    nonTerminals["Else2_2"] = new NonTerminal("Else2");
    nonTerminals["Else2_3"] = new NonTerminal("Else2");
    nonTerminals["Fstmt"] = new NonTerminal("Fstmt");
    nonTerminals["Wstmt"] = new NonTerminal("Wstmt");
    nonTerminals["Ostmt"] = new NonTerminal("Ostmt");
    nonTerminals["Y"] = new NonTerminal("Y");
    nonTerminals["Y_2"] = new NonTerminal("Y");
    nonTerminals["Astmt"] = new NonTerminal("Astmt");
    nonTerminals["Stmt"] = new NonTerminal("Stmt");
    nonTerminals["Stmt_2"] = new NonTerminal("Stmt");
    nonTerminals["Stmt_3"] = new NonTerminal("Stmt");
    nonTerminals["Stmt_4"] = new NonTerminal("Stmt");
    nonTerminals["Stmts"] = new NonTerminal("Stmts");
    nonTerminals["Stmts_2"] = new NonTerminal("Stmts");
    nonTerminals["Stmts_3"] = new NonTerminal("Stmts");
    nonTerminals["Block"] = new NonTerminal("Block");
    nonTerminals["Pgm"] = new NonTerminal("Pgm");
}

void Grammar::createRules() {
    vector<Symbol*> temp;
    
    rules.push_back(NULL); // no rule at index 0
    
    // Rule 1
    temp.push_back(terminals["kwdprog"]);
    temp.push_back(nonTerminals["Block"]);
    rules.push_back(new Rule(nonTerminals["Pgm"], temp, 0, -1, 1));
    static_cast<NonTerminal*>(rules[1]->getLhs())->setRule(rules[1]);
    temp.clear();
    
    // Rule 2
    temp.push_back(terminals["brace1"]);
    temp.push_back(nonTerminals["Stmts_3"]);
    temp.push_back(terminals["brace2"]);
    rules.push_back(new Rule(nonTerminals["Block"], temp, -2, 1, -1));
    static_cast<NonTerminal*>(rules[2]->getLhs())->setRule(rules[2]);
    temp.clear();
    
    // Rule 3
    temp.push_back(nonTerminals["Stmt"]);
    temp.push_back(terminals["semi"]);
    temp.push_back(nonTerminals["Stmts"]);
    rules.push_back(new Rule(nonTerminals["Stmts"], temp, 1, 0, 2));
    static_cast<NonTerminal*>(rules[3]->getLhs())->setRule(rules[3]);
    temp.clear();
    
    // Rule 4
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["Stmts_2"], temp, -1, -1, -1));
    static_cast<NonTerminal*>(rules[4]->getLhs())->setRule(rules[4]);
    temp.clear();
    
    // Rule 5
    temp.push_back(nonTerminals["Astmt"]);
    rules.push_back(new Rule(nonTerminals["Stmt"], temp, -2, 0, -1));
    static_cast<NonTerminal*>(rules[5]->getLhs())->setRule(rules[5]);
    temp.clear();
    
    // Rule 6
    temp.push_back(nonTerminals["Ostmt"]);
    rules.push_back(new Rule(nonTerminals["Stmt_2"], temp, -2, 0, -1));
    static_cast<NonTerminal*>(rules[6]->getLhs())->setRule(rules[6]);
    temp.clear();
    
    // Rule 7
    temp.push_back(nonTerminals["Wstmt"]);
    rules.push_back(new Rule(nonTerminals["Stmt_3"], temp, -2, 0, -1));
    static_cast<NonTerminal*>(rules[7]->getLhs())->setRule(rules[7]);
    temp.clear();
    
    // Rule 8
    temp.push_back(nonTerminals["Fstmt"]);
    rules.push_back(new Rule(nonTerminals["Stmt_4"], temp, -2, 0, -1));
    static_cast<NonTerminal*>(rules[8]->getLhs())->setRule(rules[8]);
    temp.clear();
    
    // Rule 9
    temp.push_back(terminals["id"]);
    temp.push_back(terminals["equal"]);
    temp.push_back(nonTerminals["Y"]);
    rules.push_back(new Rule(nonTerminals["Astmt"], temp, 1, 0, 2));
    static_cast<NonTerminal*>(rules[9]->getLhs())->setRule(rules[9]);
    temp.clear();
    
    // Rule 10
    temp.push_back(terminals["kwdinput"]);
    rules.push_back(new Rule(nonTerminals["Y"], temp, 0, -1, -1));
    static_cast<NonTerminal*>(rules[10]->getLhs())->setRule(rules[10]);
    temp.clear();
    
    // Rule 11
    temp.push_back(nonTerminals["E"]);
    rules.push_back(new Rule(nonTerminals["Y"], temp, -2, 0, -1));
    static_cast<NonTerminal*>(rules[11]->getLhs())->setRule(rules[11]);
    temp.clear();
    
    // Rule 12
    temp.push_back(terminals["kwdprint"]);
    temp.push_back(terminals["paren1"]);
    temp.push_back(nonTerminals["Elist"]);
    temp.push_back(terminals["paren2"]);
    rules.push_back(new Rule(nonTerminals["Ostmt"], temp, 0, -1, 2));
    static_cast<NonTerminal*>(rules[12]->getLhs())->setRule(rules[12]);
    temp.clear();
    
    // Rule 13
    temp.push_back(terminals["kwdwhile"]);
    temp.push_back(nonTerminals["Pexpr"]);
    temp.push_back(nonTerminals["Block"]);
    rules.push_back(new Rule(nonTerminals["Wstmt"], temp, 0, 1, 2));
    static_cast<NonTerminal*>(rules[13]->getLhs())->setRule(rules[13]);
    temp.clear();
    
    // Rule 14 *************************************/
    temp.push_back(terminals["kwdif"]);
    temp.push_back(nonTerminals["Pexpr"]);
    temp.push_back(nonTerminals["Block"]);
    temp.push_back(nonTerminals["Else2"]);
    rules.push_back(new Rule(nonTerminals["Fstmt"], temp, 0, 1, 2));
    static_cast<NonTerminal*>(rules[14]->getLhs())->setRule(rules[14]);
    temp.clear();
    
    // Rule 15  *************************************/
    temp.push_back(terminals["kwdelseif"]);
    temp.push_back(nonTerminals["Pexpr"]);
    temp.push_back(nonTerminals["Block"]);
    temp.push_back(nonTerminals["Else2"]);
    rules.push_back(new Rule(nonTerminals["Else2"], temp, 0, 1, 2));
    static_cast<NonTerminal*>(rules[15]->getLhs())->setRule(rules[15]);
    temp.clear();
    
    // Rule 16
    temp.push_back(terminals["kwdelse"]);
    temp.push_back(nonTerminals["Block"]);
    rules.push_back(new Rule(nonTerminals["Else2"], temp, 0, -1, 1));
    static_cast<NonTerminal*>(rules[16]->getLhs())->setRule(rules[16]);
    temp.clear();
    
    // Rule 17
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["Else2"], temp, -1, -1, -1));
    static_cast<NonTerminal*>(rules[17]->getLhs())->setRule(rules[17]);
    temp.clear();
    
    // Rule 18
    temp.push_back(nonTerminals["E"]);
    temp.push_back(nonTerminals["Elist2"]);
    rules.push_back(new Rule(nonTerminals["Elist"], temp, 0, -1, 1));
    static_cast<NonTerminal*>(rules[18]->getLhs())->setRule(rules[18]);
    temp.clear();
    
    // Rule 19
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["Elist_2"], temp, -1, -1, -1));
    static_cast<NonTerminal*>(rules[19]->getLhs())->setRule(rules[19]);
    temp.clear();
    
    // Rule 20
    temp.push_back(terminals["comma"]);
    temp.push_back(nonTerminals["Elist"]);
    rules.push_back(new Rule(nonTerminals["Elist2"], temp, 0, -1, 1));
    static_cast<NonTerminal*>(rules[20]->getLhs())->setRule(rules[20]);
    temp.clear();
    
    // Rule 21
    temp.push_back(nonTerminals["Opadd"]);
    temp.push_back(nonTerminals["T"]);
    temp.push_back(nonTerminals["R"]);
    rules.push_back(new Rule(nonTerminals["R"], temp, 0, 1, 2));
    static_cast<NonTerminal*>(rules[21]->getLhs())->setRule(rules[21]);
    temp.clear();
    
    // Rule 22
    temp.push_back(nonTerminals["T"]);
    temp.push_back(nonTerminals["R"]);
    rules.push_back(new Rule(nonTerminals["E"], temp, 0, -1, 1));
    static_cast<NonTerminal*>(rules[22]->getLhs())->setRule(rules[22]);
    temp.clear();
    
    // Rule 23
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["R"], temp, -1, -1, -1));
    static_cast<NonTerminal*>(rules[23]->getLhs())->setRule(rules[23]);
    temp.clear();
    
    // Rule 24
    temp.push_back(nonTerminals["Opmul"]);
    temp.push_back(nonTerminals["F"]);
    temp.push_back(nonTerminals["S"]);
    rules.push_back(new Rule(nonTerminals["S"], temp, 0, 1, 2));
    static_cast<NonTerminal*>(rules[24]->getLhs())->setRule(rules[24]);
    temp.clear();
    
    // Rule 25
    temp.push_back(nonTerminals["F"]);
    temp.push_back(nonTerminals["S"]);
    rules.push_back(new Rule(nonTerminals["T"], temp, 0, -1, 1));
    static_cast<NonTerminal*>(rules[25]->getLhs())->setRule(rules[25]);
    temp.clear();
                                                                                                               
    // Rule 26
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["S"], temp, -1, -1, -1));
    static_cast<NonTerminal*>(rules[26]->getLhs())->setRule(rules[26]);
    temp.clear();
    
    // Rule 27
    temp.push_back(nonTerminals["Fatom"]);
    rules.push_back(new Rule(nonTerminals["F"], temp, -2, 0, -1));
    static_cast<NonTerminal*>(rules[27]->getLhs())->setRule(rules[27]);
    temp.clear();
                                                                                                               
    // Rule 28
    temp.push_back(nonTerminals["Pexpr"]);
    rules.push_back(new Rule(nonTerminals["F"], temp, -2, 0, -1));
    static_cast<NonTerminal*>(rules[28]->getLhs())->setRule(rules[28]);
    temp.clear();
                                                                                                               
    // Rule 29
    temp.push_back(terminals["paren1"]);
    temp.push_back(nonTerminals["E"]);
    temp.push_back(terminals["paren2"]);
    rules.push_back(new Rule(nonTerminals["Pexpr"], temp, -2, 0, -1));
    static_cast<NonTerminal*>(rules[29]->getLhs())->setRule(rules[29]);
    temp.clear();
                                                                                                               
    // Rule 30
    temp.push_back(terminals["id"]);
    rules.push_back(new Rule(nonTerminals["Fatom"], temp, 0, -1, -1));
    static_cast<NonTerminal*>(rules[30]->getLhs())->setRule(rules[30]);
    temp.clear();
                                                                                                               
    // Rule 31
    temp.push_back(terminals["int"]);
    rules.push_back(new Rule(nonTerminals["Fatom"], temp, 0, -1, -1));
    static_cast<NonTerminal*>(rules[31]->getLhs())->setRule(rules[31]);
    temp.clear();
                                                                                                               
    // Rule 32
    temp.push_back(terminals["float"]);
    rules.push_back(new Rule(nonTerminals["Fatom"], temp, 0, -1, -1));
    static_cast<NonTerminal*>(rules[32]->getLhs())->setRule(rules[32]);
    temp.clear();

    // Rule 33
    temp.push_back(terminals["string"]);
    rules.push_back(new Rule(nonTerminals["Fatom"], temp, 0, -1, -1));
    static_cast<NonTerminal*>(rules[33]->getLhs())->setRule(rules[33]);
    temp.clear();
    
    // Rule 34
    temp.push_back(terminals["plus"]);
    rules.push_back(new Rule(nonTerminals["Opadd"], temp, 0, -1, -1));
    static_cast<NonTerminal*>(rules[34]->getLhs())->setRule(rules[34]);
    temp.clear();
    
    // Rule 35
    temp.push_back(terminals["minus"]);
    rules.push_back(new Rule(nonTerminals["Opadd"], temp, 0, -1, -1));
    static_cast<NonTerminal*>(rules[35]->getLhs())->setRule(rules[35]);
    temp.clear();
    
    // Rule 36
    temp.push_back(terminals["aster"]);
    rules.push_back(new Rule(nonTerminals["Opmul"], temp, 0, -1, -1));
    static_cast<NonTerminal*>(rules[36]->getLhs())->setRule(rules[36]);
    temp.clear();
    
    // Rule 37
    temp.push_back(terminals["slash"]);
    rules.push_back(new Rule(nonTerminals["Opmul"], temp, 0, -1, -1));
    static_cast<NonTerminal*>(rules[37]->getLhs())->setRule(rules[37]);
    temp.clear();
    
    // Rule 38
    temp.push_back(terminals["caret"]);
    rules.push_back(new Rule(nonTerminals["Opmul"], temp, 0, -1, -1));
    static_cast<NonTerminal*>(rules[38]->getLhs())->setRule(rules[38]);
    temp.clear();
    
    // Rule 39
    temp.push_back(terminals["eps"]);
    rules.push_back(new Rule(nonTerminals["Elist2_2"], temp, -1, -1, -1));
    static_cast<NonTerminal*>(rules[39]->getLhs())->setRule(rules[39]);
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

Rule Grammar::getRule(int ruleIx) {
   return *rules[ruleIx];
}
